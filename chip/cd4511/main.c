// Wokwi Custom Chip for CD4511 7-segment display driver
// SPDX-License-Identifier: GPL
// Copyright (C) 2023 Pat Deegan https://psychogenic.com 

#include "wokwi-api.h"
#include <stdio.h>
#include <stdlib.h>

#define NUMBITS_INPUT 4
#define GETCHIPSTATEFROM(usr_data) chip_state_t* chip = (chip_state_t*)usr_data

typedef struct {
  pin_t nLE;
  pin_t nLT;
  pin_t nBL;
} controlpins;

typedef struct {
  bool enabled;
  controlpins ctrl;
  pin_t outpins[7];
  pin_t inpins[NUMBITS_INPUT];
  
  uint8_t value;
  
  uint8_t manual_value;
  uint32_t manual_value_attribute; 
} chip_state_t;

const char * outputValues[] = {
  /*a,b,c...g*/
  "11111100",
  "01100000",
  "11011010",
  "11110010",
  "01100110",
  "10110110",
  "10111110",
  "11100000",
  "11111110",
  "11110110",
  "11101110",
  "00111110",
  "10011100",
  "01111010",
  "10011110",
  "10001110",

};

/* write the output segments */
void update_output(chip_state_t * chip) {
  
  uint8_t curVal = chip->value; 
  printf("Update chip output to %i\n", curVal);

  /* get the segment mapping */
  const char * segments = outputValues[curVal];

  /* set each output according to our map for this value */
  for (uint8_t i=0; i<8; i++) {
    if (segments[i] == '1') {
      pin_write(chip->outpins[i], HIGH);
    } else {
      pin_write(chip->outpins[i], LOW);
    }
  }
}

/* cb for latch enable pin */
void latch_enable_change(void *user_data, pin_t pin, uint32_t value) {
  GETCHIPSTATEFROM(user_data);
  if (value) {
    printf("output now disabled\n");
    chip->enabled = false;
  } else {

    printf("output now enabled\n");
    chip->enabled = true;
    update_output(chip);
  }
}

/* cb for all input pins */
void input_changed(void *user_data, pin_t pin, uint32_t value) {
  GETCHIPSTATEFROM(user_data);

  /* recalculate the value based on all input pins */
  chip->value = 0;
  for (uint8_t i=0; i<NUMBITS_INPUT; i++) {
    if (pin_read(chip->inpins[i])){
      chip->value = chip->value | (1 << i);
    }
  }
  
  if (chip->enabled) {
    update_output(chip);
  }

}

static void on_uart_rx_data(void *user_data, uint8_t byte) {
  GETCHIPSTATEFROM(user_data);

  uint8_t v = byte - '0';
  if (v < 0xf) {
    chip->value = v;
    printf("UART value set to %i\n", v);
    update_output(chip);
  } else {
    if (byte != '\n' && byte != '\r') {

    printf("Unsupported value '%c'\n", byte);
    }
  }

}


void manual_value_changed(void* user_data) {
  GETCHIPSTATEFROM(user_data);
  
  uint8_t curVal = attr_read(chip->manual_value_attribute);
  if (curVal != chip->manual_value) {
    chip->manual_value = curVal;
    chip->value = curVal;
    update_output(chip);
  }

}



/* initialize our custom chip */
void chip_init() {
  chip_state_t *chip = malloc(sizeof(chip_state_t));
  char * inputNames[] = {"D0", "D1", "D2", "D3", 0};
  char * outputNames[] = {"a", "b", "c", "d", "e", "f", "g", 0};

  /* init and stash the pins */
  uint8_t i = 0;
  while (inputNames[i] != 0) {
    chip->inpins[i] = pin_init(inputNames[i], INPUT_PULLDOWN);
    i++;
  }
  i = 0;
  while (outputNames[i] != 0) {
    chip->outpins[i] = pin_init(outputNames[i], OUTPUT_LOW);
    i++;
  }

  chip->ctrl.nLE = pin_init("nLE", INPUT_PULLDOWN);


  /* watch both the inputs and the latch enable */
  const pin_watch_config_t watch_enable = {
    .edge = BOTH,
    .pin_change = latch_enable_change,
    .user_data = chip,
  };
  pin_watch(chip->ctrl.nLE, &watch_enable);


  const pin_watch_config_t watch_inputs = {
    .edge = BOTH,
    .pin_change = input_changed,
    .user_data = chip,
  };
  for(i=0; i<NUMBITS_INPUT; i++) {
    pin_watch(chip->inpins[i], &watch_inputs);
  }

  /* enable if enabled... */
  if (pin_read(chip->ctrl.nLE)) {
    chip->enabled = false;
  } else {
    chip->enabled = true;
    update_output(chip);
  }


  chip->manual_value_attribute =  attr_init("value", 0);

  const timer_config_t valuewatchtimerconf = {
    .callback = manual_value_changed,
    .user_data = chip,
  };
  timer_t valwatchtimer = timer_init(&valuewatchtimerconf);
  timer_start(valwatchtimer, 5000, true);

  const uart_config_t uart1 = {
    .rx = pin_init("nBL", INPUT),
    .baud_rate = 115200,
    .rx_data = on_uart_rx_data,
    .user_data = chip,
  };
  uart_init(&uart1);
}
