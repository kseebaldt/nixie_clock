EESchema Schematic File Version 4
LIBS:NixieClock-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Nixies:IN-12A NX2
U 1 1 5D02FFCC
P 3100 1200
F 0 "NX2" H 3050 2045 45  0000 C CNN
F 1 "IN-12A" H 3100 1200 45  0001 L BNN
F 2 "Nixies:nixies-us-IN-12-DSUB" H 3130 1350 20  0001 C CNN
F 3 "" H 3100 1200 50  0001 C CNN
	1    3100 1200
	0    -1   -1   0   
$EndComp
$Comp
L Nixies:IN-12A NX1
U 1 1 5D030BC8
P 1450 1200
F 0 "NX1" H 1400 2045 45  0000 C CNN
F 1 "IN-12A" H 1450 1200 45  0001 L BNN
F 2 "Nixies:nixies-us-IN-12-DSUB" H 1480 1350 20  0001 C CNN
F 3 "" H 1450 1200 50  0001 C CNN
	1    1450 1200
	0    -1   -1   0   
$EndComp
$Comp
L Nixies:INS-1 N1
U 1 1 5D037A0C
P 7750 1200
F 0 "N1" H 7950 1370 45  0000 C CNN
F 1 "INS-1" H 7750 1200 45  0001 L BNN
F 2 "Nixies:INS-1" H 7780 1350 20  0001 C CNN
F 3 "" H 7750 1200 50  0001 C CNN
	1    7750 1200
	0    1    1    0   
$EndComp
$Comp
L 74xx_IEEE:74141 U3
U 1 1 5D039EE6
P 2950 2600
F 0 "U3" V 2996 1972 50  0000 R CNN
F 1 "74141" V 2905 1972 50  0000 R CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 2950 2600 50  0001 C CNN
F 3 "" H 2950 2600 50  0001 C CNN
	1    2950 2600
	0    -1   -1   0   
$EndComp
$Comp
L 74xx_IEEE:74141 U1
U 1 1 5D03ABD0
P 1300 2600
F 0 "U1" H 1300 3341 50  0000 C CNN
F 1 "74141" H 1300 3250 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 1300 2600 50  0001 C CNN
F 3 "" H 1300 2600 50  0001 C CNN
	1    1300 2600
	0    -1   -1   0   
$EndComp
$Comp
L Nixies:IN-12A NX4
U 1 1 5D02F54C
P 6400 1200
F 0 "NX4" H 6350 2045 45  0000 C CNN
F 1 "IN-12A" H 6400 1200 45  0001 L BNN
F 2 "Nixies:nixies-us-IN-12-DSUB" H 6430 1350 20  0001 C CNN
F 3 "" H 6400 1200 50  0001 C CNN
	1    6400 1200
	0    -1   -1   0   
$EndComp
$Comp
L Nixies:INS-1 N2
U 1 1 5D0349A6
P 8400 1200
F 0 "N2" H 8600 1370 45  0000 C CNN
F 1 "INS-1" H 8400 1200 45  0001 L BNN
F 2 "Nixies:INS-1" H 8430 1350 20  0001 C CNN
F 3 "" H 8400 1200 50  0001 C CNN
	1    8400 1200
	0    1    1    0   
$EndComp
$Comp
L Nixies:POWER-1363 U7
U 1 1 5D052087
P 9150 2750
F 0 "U7" H 9500 2981 50  0000 C CNN
F 1 "POWER-1363" H 9500 2890 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x06_P2.54mm_Vertical" H 9150 2750 50  0001 C CNN
F 3 "" H 9150 2750 50  0001 C CNN
	1    9150 2750
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5D073531
P 6550 750
F 0 "R4" H 6480 704 50  0000 R CNN
F 1 "15k" H 6480 795 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 6480 750 50  0001 C CNN
F 3 "~" H 6550 750 50  0001 C CNN
	1    6550 750 
	-1   0    0    1   
$EndComp
$Comp
L Device:R R1
U 1 1 5D09314D
P 1600 750
F 0 "R1" H 1530 704 50  0000 R CNN
F 1 "15k" H 1530 795 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 1530 750 50  0001 C CNN
F 3 "~" H 1600 750 50  0001 C CNN
	1    1600 750 
	-1   0    0    1   
$EndComp
$Comp
L Device:R R5
U 1 1 5D095FC6
P 7650 850
F 0 "R5" V 7443 850 50  0000 C CNN
F 1 "220k" V 7534 850 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 7580 850 50  0001 C CNN
F 3 "~" H 7650 850 50  0001 C CNN
	1    7650 850 
	-1   0    0    1   
$EndComp
Wire Wire Line
	7650 700  7650 600 
Wire Wire Line
	7650 1000 7650 1100
$Comp
L Device:R R6
U 1 1 5D09AD15
P 8300 850
F 0 "R6" V 8093 850 50  0000 C CNN
F 1 "220k" V 8184 850 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 8230 850 50  0001 C CNN
F 3 "~" H 8300 850 50  0001 C CNN
	1    8300 850 
	-1   0    0    1   
$EndComp
Wire Wire Line
	8300 600  8300 700 
Wire Wire Line
	8300 1000 8300 1100
$Comp
L Buffers_Line_Drivers:SN74AHCT125N IC2
U 1 1 5D0BCFF5
P 1950 4850
F 0 "IC2" H 2500 5115 50  0000 C CNN
F 1 "SN74AHCT125N" H 2500 5024 50  0000 C CNN
F 2 "Package_DIP:DIP-14_W7.62mm_Socket" H 2900 4950 50  0001 L CNN
F 3 "http://www.ti.com/lit/gpn/sn74ahct125" H 2900 4850 50  0001 L CNN
F 4 "Quadruple Bus Buffer Gates With 3-State Outputs" H 2900 4750 50  0001 L CNN "Description"
	1    1950 4850
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR01
U 1 1 5D0CDDC8
P 4350 5300
F 0 "#PWR01" H 4350 5150 50  0001 C CNN
F 1 "+5V" H 4365 5473 50  0000 C CNN
F 2 "" H 4350 5300 50  0001 C CNN
F 3 "" H 4350 5300 50  0001 C CNN
	1    4350 5300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 5450 4350 5300
Wire Wire Line
	8300 600  7650 600 
Wire Wire Line
	950  2000 950  1700
Wire Wire Line
	1050 2000 1050 1700
Wire Wire Line
	1150 2000 1150 1700
Wire Wire Line
	1250 1700 1250 2000
Wire Wire Line
	1350 2000 1350 1700
Wire Wire Line
	1450 1700 1450 2000
Wire Wire Line
	1550 2000 1550 1700
Wire Wire Line
	1650 1700 1650 2000
Wire Wire Line
	1750 2000 1750 1700
Wire Wire Line
	1850 1700 1850 1850
Wire Wire Line
	1850 1850 850  1850
Wire Wire Line
	850  1850 850  2000
Wire Wire Line
	2600 1700 2600 2000
Wire Wire Line
	2700 2000 2700 1700
Wire Wire Line
	2800 1700 2800 2000
Wire Wire Line
	2900 2000 2900 1700
Wire Wire Line
	3000 1700 3000 2000
Wire Wire Line
	3100 2000 3100 1700
Wire Wire Line
	3200 1700 3200 2000
Wire Wire Line
	3300 2000 3300 1700
Wire Wire Line
	3400 1700 3400 2000
Wire Wire Line
	3500 1700 3500 1900
Wire Wire Line
	3500 1900 2500 1900
Wire Wire Line
	2500 1900 2500 2000
$Comp
L Device:R R3
U 1 1 5D0C920B
P 4900 750
F 0 "R3" H 4830 704 50  0000 R CNN
F 1 "15k" H 4830 795 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4830 750 50  0001 C CNN
F 3 "~" H 4900 750 50  0001 C CNN
	1    4900 750 
	-1   0    0    1   
$EndComp
$Comp
L Nixies:IN-12A NX3
U 1 1 5D03165D
P 4750 1200
F 0 "NX3" H 4700 2045 45  0000 C CNN
F 1 "IN-12A" H 4750 1200 45  0001 L BNN
F 2 "Nixies:nixies-us-IN-12-DSUB" H 4780 1350 20  0001 C CNN
F 3 "" H 4750 1200 50  0001 C CNN
	1    4750 1200
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R2
U 1 1 5D08698A
P 3250 750
F 0 "R2" H 3180 704 50  0000 R CNN
F 1 "15k" H 3180 795 50  0000 R CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 3180 750 50  0001 C CNN
F 3 "~" H 3250 750 50  0001 C CNN
	1    3250 750 
	-1   0    0    1   
$EndComp
Wire Wire Line
	4250 2000 4250 1700
Wire Wire Line
	4350 1700 4350 2000
Wire Wire Line
	4450 2000 4450 1700
Wire Wire Line
	4550 1700 4550 2000
Wire Wire Line
	4650 2000 4650 1700
Wire Wire Line
	4750 1700 4750 2000
Wire Wire Line
	4850 2000 4850 1700
Wire Wire Line
	4950 1700 4950 2000
Wire Wire Line
	5050 2000 5050 1700
Wire Wire Line
	5150 1700 5150 1850
Wire Wire Line
	5150 1850 4150 1850
Wire Wire Line
	4150 1850 4150 2000
Wire Wire Line
	5900 2000 5900 1700
Wire Wire Line
	6000 2000 6000 1700
Wire Wire Line
	6100 2000 6100 1700
Wire Wire Line
	6200 2000 6200 1700
Wire Wire Line
	6300 2000 6300 1700
Wire Wire Line
	6400 2000 6400 1700
Wire Wire Line
	6500 2000 6500 1700
Wire Wire Line
	6600 2000 6600 1700
Wire Wire Line
	6700 2000 6700 1700
Wire Wire Line
	1450 800  1500 800 
Wire Wire Line
	1500 800  1500 900 
Wire Wire Line
	1500 900  1600 900 
Wire Wire Line
	3100 800  3150 800 
Wire Wire Line
	3150 800  3150 900 
Wire Wire Line
	3150 900  3250 900 
Wire Wire Line
	4750 800  4800 800 
Wire Wire Line
	4800 800  4800 900 
Wire Wire Line
	4800 900  4900 900 
Wire Wire Line
	6400 800  6450 800 
Wire Wire Line
	6450 800  6450 900 
Wire Wire Line
	6450 900  6550 900 
Wire Wire Line
	1600 600  3250 600 
Wire Wire Line
	3250 600  4900 600 
Connection ~ 3250 600 
Wire Wire Line
	4900 600  6550 600 
Connection ~ 4900 600 
Wire Wire Line
	5800 2000 5800 1900
Wire Wire Line
	5800 1900 6800 1900
Wire Wire Line
	6800 1900 6800 1700
Wire Wire Line
	6550 600  7650 600 
Connection ~ 6550 600 
Connection ~ 7650 600 
Connection ~ 8300 600 
$Comp
L Device:R R7
U 1 1 5D1FDF75
P 10300 3200
F 0 "R7" H 10370 3246 50  0000 L CNN
F 1 "47k" H 10370 3155 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 10230 3200 50  0001 C CNN
F 3 "~" H 10300 3200 50  0001 C CNN
	1    10300 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	10100 3050 10300 3050
$Comp
L power:GND #PWR08
U 1 1 5D2006B6
P 10100 3800
F 0 "#PWR08" H 10100 3550 50  0001 C CNN
F 1 "GND" H 10105 3627 50  0000 C CNN
F 2 "" H 10100 3800 50  0001 C CNN
F 3 "" H 10100 3800 50  0001 C CNN
	1    10100 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	10300 3350 10300 3800
Wire Wire Line
	10300 3800 10100 3800
Wire Wire Line
	9900 3450 9900 3800
Wire Wire Line
	9800 3450 9800 3800
Wire Wire Line
	9800 3800 9900 3800
Connection ~ 9900 3800
Wire Wire Line
	9700 3450 9700 3800
Wire Wire Line
	9700 3800 9800 3800
Connection ~ 9800 3800
Wire Wire Line
	9600 3450 9600 3800
Wire Wire Line
	9600 3800 9700 3800
Connection ~ 9700 3800
Wire Wire Line
	9500 3450 9500 3800
Wire Wire Line
	9500 3800 9600 3800
Connection ~ 9600 3800
Wire Wire Line
	9400 3450 9400 3800
Wire Wire Line
	9400 3800 9500 3800
Connection ~ 9500 3800
Wire Wire Line
	9900 3800 10100 3800
Connection ~ 10100 3800
$Comp
L power:GND #PWR04
U 1 1 5D275682
P 1300 5450
F 0 "#PWR04" H 1300 5200 50  0001 C CNN
F 1 "GND" H 1305 5277 50  0000 C CNN
F 2 "" H 1300 5450 50  0001 C CNN
F 3 "" H 1300 5450 50  0001 C CNN
	1    1300 5450
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR03
U 1 1 5D2759D5
P 950 6650
F 0 "#PWR03" H 950 6400 50  0001 C CNN
F 1 "GND" V 955 6522 50  0000 R CNN
F 2 "" H 950 6650 50  0001 C CNN
F 3 "" H 950 6650 50  0001 C CNN
	1    950  6650
	0    1    1    0   
$EndComp
$Comp
L ESP32:ESP32-EzSBC IC1
U 1 1 5D291A41
P 1500 7400
F 0 "IC1" H 2200 7665 50  0000 C CNN
F 1 "ESP32-EzSBC" H 2200 7574 50  0000 C CNN
F 2 "ESP32:ESP32-EzSBC" H 2750 7500 50  0001 L CNN
F 3 "http://www.mouser.com/datasheet/2/891/esp32-wrover-b_datasheet_en-1384674.pdf" H 2750 7400 50  0001 L CNN
	1    1500 7400
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5D2B682C
P 6350 5600
F 0 "#PWR02" H 6350 5350 50  0001 C CNN
F 1 "GND" H 6355 5427 50  0000 C CNN
F 2 "" H 6350 5600 50  0001 C CNN
F 3 "" H 6350 5600 50  0001 C CNN
	1    6350 5600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR05
U 1 1 5D324ED3
P 3800 6650
F 0 "#PWR05" H 3800 6400 50  0001 C CNN
F 1 "GND" H 3805 6477 50  0000 C CNN
F 2 "" H 3800 6650 50  0001 C CNN
F 3 "" H 3800 6650 50  0001 C CNN
	1    3800 6650
	0    -1   -1   0   
$EndComp
$Comp
L Transistor_BJT:MPSA42 Q1
U 1 1 5D403F34
P 7550 2500
F 0 "Q1" H 7741 2546 50  0000 L CNN
F 1 "MPSA42" H 7741 2455 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 7750 2425 50  0001 L CIN
F 3 "http://www.onsemi.com/pub_link/Collateral/MPSA42-D.PDF" H 7550 2500 50  0001 L CNN
	1    7550 2500
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:MPSA42 Q2
U 1 1 5D427670
P 8200 2150
F 0 "Q2" H 8391 2196 50  0000 L CNN
F 1 "MPSA42" H 8391 2105 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 8400 2075 50  0001 L CIN
F 3 "http://www.onsemi.com/pub_link/Collateral/MPSA42-D.PDF" H 8200 2150 50  0001 L CNN
	1    8200 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 1700 8300 1950
Wire Wire Line
	7650 1700 7650 2300
$Comp
L power:GND #PWR07
U 1 1 5D4685E7
P 8050 3100
F 0 "#PWR07" H 8050 2850 50  0001 C CNN
F 1 "GND" H 8055 2927 50  0000 C CNN
F 2 "" H 8050 3100 50  0001 C CNN
F 3 "" H 8050 3100 50  0001 C CNN
	1    8050 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7650 2700 7650 3000
Wire Wire Line
	7650 3000 8050 3000
Wire Wire Line
	8050 3000 8050 3100
Wire Wire Line
	8300 2350 8300 3000
Wire Wire Line
	8300 3000 8050 3000
Connection ~ 8050 3000
$Comp
L Switch:SW_Push SW1
U 1 1 5D484662
P 4600 7450
F 0 "SW1" H 4600 7735 50  0000 C CNN
F 1 "SW_Push" H 4600 7644 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 4600 7650 50  0001 C CNN
F 3 "~" H 4600 7650 50  0001 C CNN
	1    4600 7450
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5D4C26E0
P 10450 6100
F 0 "#FLG0101" H 10450 6175 50  0001 C CNN
F 1 "PWR_FLAG" H 10450 6273 50  0000 C CNN
F 2 "" H 10450 6100 50  0001 C CNN
F 3 "~" H 10450 6100 50  0001 C CNN
	1    10450 6100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4350 5450 4600 5450
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5D4EEB20
P 11000 6100
F 0 "#FLG0102" H 11000 6175 50  0001 C CNN
F 1 "PWR_FLAG" H 11000 6273 50  0000 C CNN
F 2 "" H 11000 6100 50  0001 C CNN
F 3 "~" H 11000 6100 50  0001 C CNN
	1    11000 6100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5D4EF49D
P 10450 6250
F 0 "#PWR0101" H 10450 6000 50  0001 C CNN
F 1 "GND" H 10455 6077 50  0000 C CNN
F 2 "" H 10450 6250 50  0001 C CNN
F 3 "" H 10450 6250 50  0001 C CNN
	1    10450 6250
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0102
U 1 1 5D4EFC55
P 11000 6250
F 0 "#PWR0102" H 11000 6100 50  0001 C CNN
F 1 "+5V" H 11015 6423 50  0000 C CNN
F 2 "" H 11000 6250 50  0001 C CNN
F 3 "" H 11000 6250 50  0001 C CNN
	1    11000 6250
	-1   0    0    1   
$EndComp
Wire Wire Line
	11000 6100 11000 6250
Wire Wire Line
	10450 6100 10450 6250
$Comp
L power:+5V #PWR0103
U 1 1 5D50E3B3
P 10150 4950
F 0 "#PWR0103" H 10150 4800 50  0001 C CNN
F 1 "+5V" H 10165 5123 50  0000 C CNN
F 2 "" H 10150 4950 50  0001 C CNN
F 3 "" H 10150 4950 50  0001 C CNN
	1    10150 4950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 5D50EE12
P 10150 5200
F 0 "#PWR0104" H 10150 4950 50  0001 C CNN
F 1 "GND" H 10155 5027 50  0000 C CNN
F 2 "" H 10150 5200 50  0001 C CNN
F 3 "" H 10150 5200 50  0001 C CNN
	1    10150 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	9750 5200 10150 5200
Wire Wire Line
	9750 5000 10150 5000
Wire Wire Line
	10150 5000 10150 4950
$Comp
L Connector:USB_B_Micro J1
U 1 1 5D54BD5E
P 9200 5100
F 0 "J1" H 9257 5567 50  0000 C CNN
F 1 "USB_B_Micro" H 9257 5476 50  0000 C CNN
F 2 "Connector_USB:USB_Micro-B_Molex-105017-0001" H 9350 5050 50  0001 C CNN
F 3 "~" H 9350 5050 50  0001 C CNN
	1    9200 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	9500 4900 9750 4900
Wire Wire Line
	9750 4900 9750 5000
Wire Wire Line
	9200 5500 9750 5500
Wire Wire Line
	9750 5500 9750 5200
Wire Wire Line
	9100 5500 9200 5500
Connection ~ 9200 5500
$Comp
L 74xx_IEEE:74141 U4
U 1 1 5D03B400
P 4600 2600
F 0 "U4" V 4646 1972 50  0000 R CNN
F 1 "74141" V 4555 1972 50  0000 R CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 4600 2600 50  0001 C CNN
F 3 "" H 4600 2600 50  0001 C CNN
	1    4600 2600
	0    -1   -1   0   
$EndComp
$Comp
L 74xx_IEEE:74141 U6
U 1 1 5D0388AE
P 6250 2600
F 0 "U6" H 6250 3341 50  0000 C CNN
F 1 "74141" H 6250 3250 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 6250 2600 50  0001 C CNN
F 3 "" H 6250 2600 50  0001 C CNN
	1    6250 2600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2850 3950 1150 3950
Wire Wire Line
	1150 3950 1150 3200
Wire Wire Line
	1250 3200 1250 3900
Wire Wire Line
	1250 3900 2950 3900
Wire Wire Line
	2950 3900 2950 3950
Wire Wire Line
	1350 3200 1350 3850
Wire Wire Line
	1350 3850 3050 3850
Wire Wire Line
	3050 3850 3050 3950
Wire Wire Line
	1450 3200 1450 3800
Wire Wire Line
	1450 3800 3150 3800
Wire Wire Line
	3150 3800 3150 3950
Wire Wire Line
	2800 3200 2800 3750
Wire Wire Line
	2800 3750 3250 3750
Wire Wire Line
	3250 3750 3250 3950
Wire Wire Line
	2900 3200 2900 3700
Wire Wire Line
	2900 3700 3350 3700
Wire Wire Line
	3350 3700 3350 3950
Wire Wire Line
	3000 3200 3000 3650
Wire Wire Line
	3000 3650 3450 3650
Wire Wire Line
	3450 3650 3450 3950
Wire Wire Line
	3100 3200 3100 3600
Wire Wire Line
	3100 3600 3550 3600
Wire Wire Line
	3550 3600 3550 3950
Wire Wire Line
	4450 3200 3650 3200
Wire Wire Line
	3650 3200 3650 3950
Wire Wire Line
	4550 3200 4550 3300
Wire Wire Line
	4550 3300 3750 3300
Wire Wire Line
	3750 3300 3750 3950
Wire Wire Line
	4650 3200 4650 3350
Wire Wire Line
	4650 3350 3850 3350
Wire Wire Line
	3850 3350 3850 3950
Wire Wire Line
	4750 3200 4750 3400
Wire Wire Line
	4750 3400 3950 3400
Wire Wire Line
	3950 3400 3950 3950
Wire Wire Line
	6100 3200 6100 3450
Wire Wire Line
	6100 3450 4050 3450
Wire Wire Line
	4050 3450 4050 3950
Wire Wire Line
	6200 3200 6200 3500
Wire Wire Line
	6200 3500 4150 3500
Wire Wire Line
	4150 3500 4150 3950
Wire Wire Line
	6300 3200 6300 3550
Wire Wire Line
	6300 3550 4250 3550
Wire Wire Line
	4250 3550 4250 3950
Wire Wire Line
	6400 3200 6400 3600
Wire Wire Line
	6400 3600 4350 3600
Wire Wire Line
	4350 3600 4350 3950
Wire Wire Line
	6950 2150 6950 3650
Wire Wire Line
	6950 3650 4450 3650
Wire Wire Line
	4450 3650 4450 3950
Wire Wire Line
	6950 2150 8000 2150
Wire Wire Line
	7350 2500 7000 2500
Wire Wire Line
	7000 2500 7000 3700
Wire Wire Line
	7000 3700 4550 3700
Wire Wire Line
	4550 3700 4550 3950
Wire Wire Line
	8400 2900 8400 3050
Wire Wire Line
	8400 3750 5050 3750
Wire Wire Line
	8900 3050 8400 3050
Connection ~ 8400 3050
Wire Wire Line
	8400 3050 8400 3750
$Comp
L power:GND #PWR010
U 1 1 5D82D1DE
P 5150 3950
F 0 "#PWR010" H 5150 3700 50  0001 C CNN
F 1 "GND" V 5155 3822 50  0000 R CNN
F 2 "" H 5150 3950 50  0001 C CNN
F 3 "" H 5150 3950 50  0001 C CNN
	1    5150 3950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5250 4350 5600 4350
Wire Wire Line
	5350 4400 5700 4400
Wire Wire Line
	5450 4450 5800 4450
Wire Wire Line
	5550 4500 5900 4500
Wire Wire Line
	5650 4550 6000 4550
Wire Wire Line
	5750 4600 6100 4600
Wire Wire Line
	5850 4650 6200 4650
Wire Wire Line
	5950 4700 6300 4700
Wire Wire Line
	7600 4600 7600 5050
Wire Wire Line
	7100 4600 7600 4600
Wire Wire Line
	7500 4650 7000 4650
Wire Wire Line
	7500 5050 7500 4650
Wire Wire Line
	7400 4700 6900 4700
Wire Wire Line
	7400 5050 7400 4700
Wire Wire Line
	7300 4750 6800 4750
Wire Wire Line
	7300 5050 7300 4750
Wire Wire Line
	7200 4800 6700 4800
Wire Wire Line
	7200 5050 7200 4800
Wire Wire Line
	7100 4850 6600 4850
Wire Wire Line
	7100 5050 7100 4850
Wire Wire Line
	7000 4900 6500 4900
Wire Wire Line
	7000 5050 7000 4900
Wire Wire Line
	6900 4950 6400 4950
Wire Wire Line
	6900 5050 6900 4950
$Comp
L 74xx:74HC595 U2
U 1 1 5D0B5850
P 5650 5450
F 0 "U2" V 5696 4706 50  0000 R CNN
F 1 "74HC595" V 5605 4706 50  0000 R CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 5650 5450 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 5650 5450 50  0001 C CNN
	1    5650 5450
	0    -1   -1   0   
$EndComp
$Comp
L 74xx:74HC595 U5
U 1 1 5D0B4236
P 7300 5450
F 0 "U5" V 7346 4706 50  0000 R CNN
F 1 "74HC595" V 7255 4706 50  0000 R CNN
F 2 "Package_DIP:DIP-16_W7.62mm_Socket" H 7300 5450 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 7300 5450 50  0001 C CNN
	1    7300 5450
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR011
U 1 1 5DC6255E
P 8300 4350
F 0 "#PWR011" H 8300 4100 50  0001 C CNN
F 1 "GND" V 8305 4222 50  0000 R CNN
F 2 "" H 8300 4350 50  0001 C CNN
F 3 "" H 8300 4350 50  0001 C CNN
	1    8300 4350
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9750 4450 9750 4900
Connection ~ 9750 4900
Wire Wire Line
	5350 4400 5350 5050
Wire Wire Line
	5450 4450 5450 5050
Wire Wire Line
	5550 4500 5550 5050
Wire Wire Line
	5650 4550 5650 5050
Wire Wire Line
	5750 4600 5750 5050
Wire Wire Line
	5850 4650 5850 5050
Wire Wire Line
	5950 4700 5950 5050
Wire Wire Line
	9100 5500 9100 5650
Wire Wire Line
	9100 5650 8000 5650
Wire Wire Line
	8000 5650 8000 5450
Connection ~ 9100 5500
Wire Wire Line
	6350 5450 6350 5550
Wire Wire Line
	2700 6000 2700 5750
Wire Wire Line
	2700 5750 1700 5750
Wire Wire Line
	1700 5750 1700 4950
Wire Wire Line
	1700 4950 1950 4950
Wire Wire Line
	5250 4350 5250 5050
Wire Wire Line
	2800 6000 2800 5700
Wire Wire Line
	2800 5700 1750 5700
Wire Wire Line
	1750 5700 1750 5250
Wire Wire Line
	1750 5250 1950 5250
Wire Wire Line
	3050 5350 3200 5350
Wire Wire Line
	7300 4500 8400 4500
Wire Wire Line
	3400 7400 3800 7400
Wire Wire Line
	3800 7400 3800 6650
Wire Wire Line
	3200 6000 3200 5900
Wire Wire Line
	3200 5900 3800 5900
Wire Wire Line
	3800 5900 3800 6650
Connection ~ 3800 6650
$Comp
L power:+5V #PWR09
U 1 1 5E03686D
P 3600 7650
F 0 "#PWR09" H 3600 7500 50  0001 C CNN
F 1 "+5V" V 3615 7778 50  0000 L CNN
F 2 "" H 3600 7650 50  0001 C CNN
F 3 "" H 3600 7650 50  0001 C CNN
	1    3600 7650
	0    1    1    0   
$EndComp
Wire Wire Line
	3300 7400 3300 7650
Wire Wire Line
	3300 7650 3600 7650
Wire Wire Line
	1800 7400 1800 7650
Wire Wire Line
	1800 7650 3300 7650
Connection ~ 3300 7650
$Comp
L power:+5V #PWR06
U 1 1 5E05DAC2
P 800 5800
F 0 "#PWR06" H 800 5650 50  0001 C CNN
F 1 "+5V" V 815 5928 50  0000 L CNN
F 2 "" H 800 5800 50  0001 C CNN
F 3 "" H 800 5800 50  0001 C CNN
	1    800  5800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1600 6000 1600 5900
Wire Wire Line
	1600 5800 800  5800
Wire Wire Line
	3100 6000 3100 5900
Wire Wire Line
	3100 5900 1600 5900
Connection ~ 1600 5900
Wire Wire Line
	1600 5900 1600 5800
Wire Wire Line
	1500 6000 950  6000
Wire Wire Line
	950  6000 950  6650
Wire Wire Line
	1700 7400 1700 7550
Wire Wire Line
	1700 7550 950  7550
Wire Wire Line
	950  7550 950  6650
Connection ~ 950  6650
Wire Wire Line
	4800 7450 4800 5450
Connection ~ 4800 5450
Wire Wire Line
	4800 5450 4950 5450
Wire Wire Line
	1950 5450 1350 5450
Wire Wire Line
	4600 5450 4600 4850
Wire Wire Line
	4600 4850 3050 4850
Connection ~ 4600 5450
Wire Wire Line
	4600 5450 4800 5450
Wire Wire Line
	6700 5450 6700 6400
Wire Wire Line
	6700 6500 4600 6500
Wire Wire Line
	4600 6500 4600 5450
Wire Wire Line
	6900 5850 6500 5850
Wire Wire Line
	6500 5850 6500 5050
Wire Wire Line
	6500 5050 6150 5050
Wire Wire Line
	1950 5150 1350 5150
Wire Wire Line
	1350 5150 1350 5450
Connection ~ 1350 5450
Wire Wire Line
	1350 5450 1300 5450
Wire Wire Line
	1950 4850 1350 4850
Wire Wire Line
	1350 4850 1350 5150
Connection ~ 1350 5150
Wire Wire Line
	1350 4500 1350 4850
Connection ~ 1350 4850
Wire Wire Line
	3050 5250 3200 5250
Wire Wire Line
	1350 4500 3200 4500
Wire Wire Line
	3050 5450 3950 5450
Wire Wire Line
	3950 5450 3950 6200
Wire Wire Line
	3950 6200 5750 6200
Wire Wire Line
	5750 6200 5750 5850
Wire Wire Line
	4850 5650 4850 6150
Wire Wire Line
	4850 6150 5450 6150
Wire Wire Line
	5450 6150 5450 5850
Wire Wire Line
	1950 5050 1850 5050
Wire Wire Line
	1850 5050 1850 4450
Wire Wire Line
	1850 4450 5000 4450
Wire Wire Line
	5000 4450 5000 5900
Wire Wire Line
	5000 5900 5250 5900
Wire Wire Line
	5250 5900 5250 5850
Wire Wire Line
	5750 6200 7400 6200
Wire Wire Line
	7400 6200 7400 5850
Connection ~ 5750 6200
Wire Wire Line
	5450 6150 7100 6150
Wire Wire Line
	7100 6150 7100 5850
Connection ~ 5450 6150
$Comp
L Device:C C2
U 1 1 5E3879F7
P 7450 6400
F 0 "C2" V 7702 6400 50  0000 C CNN
F 1 "0.1uF" V 7611 6400 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D7.5mm_W5.0mm_P5.00mm" H 7488 6250 50  0001 C CNN
F 3 "~" H 7450 6400 50  0001 C CNN
	1    7450 6400
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C1
U 1 1 5E389014
P 5700 6850
F 0 "C1" V 5952 6850 50  0000 C CNN
F 1 "0.1uF" V 5861 6850 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D7.5mm_W5.0mm_P5.00mm" H 5738 6700 50  0001 C CNN
F 3 "~" H 5700 6850 50  0001 C CNN
	1    5700 6850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4950 5450 4950 6850
Wire Wire Line
	4950 6850 5550 6850
Connection ~ 4950 5450
Wire Wire Line
	4950 5450 5050 5450
Wire Wire Line
	6350 5550 6300 5550
Wire Wire Line
	6300 5550 6300 6850
Wire Wire Line
	6300 6850 5850 6850
Connection ~ 6350 5550
Wire Wire Line
	6350 5550 6350 5600
Wire Wire Line
	6700 6400 7300 6400
Connection ~ 6700 6400
Wire Wire Line
	6700 6400 6700 6500
Wire Wire Line
	8000 5650 8000 6400
Wire Wire Line
	8000 6400 7600 6400
Connection ~ 8000 5650
Wire Wire Line
	1950 5350 1850 5350
Wire Wire Line
	1850 5350 1850 5650
Wire Wire Line
	2900 5600 3200 5600
Wire Wire Line
	3200 5600 3200 5350
Wire Wire Line
	2900 5600 2900 6000
Wire Wire Line
	4850 5650 1850 5650
$Comp
L Device:LED_ARGB D1
U 1 1 5E5BC067
P 9400 1200
F 0 "D1" H 9400 1697 50  0000 C CNN
F 1 "LED_ARGB" H 9400 1606 50  0000 C CNN
F 2 "LED_SMD:LED_RGB_1210" H 9400 1150 50  0001 C CNN
F 3 "~" H 9400 1150 50  0001 C CNN
	1    9400 1200
	1    0    0    -1  
$EndComp
$Comp
L Device:LED_ARGB D2
U 1 1 5E6086B2
P 9400 2100
F 0 "D2" H 9400 2597 50  0000 C CNN
F 1 "LED_ARGB" H 9400 2506 50  0000 C CNN
F 2 "LED_SMD:LED_RGB_1210" H 9400 2050 50  0001 C CNN
F 3 "~" H 9400 2050 50  0001 C CNN
	1    9400 2100
	1    0    0    -1  
$EndComp
$Comp
L Device:LED_ARGB D3
U 1 1 5E6093D3
P 10300 1200
F 0 "D3" H 10300 1697 50  0000 C CNN
F 1 "LED_ARGB" H 10300 1606 50  0000 C CNN
F 2 "LED_SMD:LED_RGB_1210" H 10300 1150 50  0001 C CNN
F 3 "~" H 10300 1150 50  0001 C CNN
	1    10300 1200
	1    0    0    -1  
$EndComp
$Comp
L Device:LED_ARGB D4
U 1 1 5E60A356
P 10300 2100
F 0 "D4" H 10300 2597 50  0000 C CNN
F 1 "LED_ARGB" H 10300 2506 50  0000 C CNN
F 2 "LED_SMD:LED_RGB_1210" H 10300 2050 50  0001 C CNN
F 3 "~" H 10300 2050 50  0001 C CNN
	1    10300 2100
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x24_Male J2
U 1 1 5E6305D0
P 3950 4150
F 0 "J2" V 3877 4078 50  0000 C CNN
F 1 "Conn_01x24_Male" V 3786 4078 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x24_P2.54mm_Vertical" H 3950 4150 50  0001 C CNN
F 3 "~" H 3950 4150 50  0001 C CNN
	1    3950 4150
	0    -1   -1   0   
$EndComp
Text Label 4650 3850 0    50   ~ 0
R
Text Label 4750 3850 0    50   ~ 0
G
Wire Wire Line
	4650 3950 4650 3850
Wire Wire Line
	4750 3950 4750 3850
Wire Wire Line
	4850 3950 4850 3850
Text Label 4850 3850 0    50   ~ 0
B
Text Label 8650 1900 0    50   ~ 0
R
Text Label 8650 2100 0    50   ~ 0
G
Text Label 8650 2300 0    50   ~ 0
B
Wire Wire Line
	8900 2900 8400 2900
$Comp
L Device:R_Small R14
U 1 1 5E9C18EE
P 10000 1000
F 0 "R14" V 9804 1000 50  0000 C CNN
F 1 "100" V 9895 1000 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 10000 1000 50  0001 C CNN
F 3 "~" H 10000 1000 50  0001 C CNN
	1    10000 1000
	0    1    1    0   
$EndComp
Wire Wire Line
	8400 2450 8400 2900
Connection ~ 8400 2900
Wire Wire Line
	10500 2450 10500 2100
Wire Wire Line
	10500 2100 10500 1200
Connection ~ 10500 2100
$Comp
L Device:R_Small R9
U 1 1 5EBCDFF1
P 9100 1200
F 0 "R9" V 8904 1200 50  0000 C CNN
F 1 "150" V 8995 1200 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 9100 1200 50  0001 C CNN
F 3 "~" H 9100 1200 50  0001 C CNN
	1    9100 1200
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R17
U 1 1 5EBEEC24
P 10000 1900
F 0 "R17" V 9804 1900 50  0000 C CNN
F 1 "100" V 9895 1900 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 10000 1900 50  0001 C CNN
F 3 "~" H 10000 1900 50  0001 C CNN
	1    10000 1900
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R8
U 1 1 5EBEF026
P 9100 1000
F 0 "R8" V 8904 1000 50  0000 C CNN
F 1 "100" V 8995 1000 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 9100 1000 50  0001 C CNN
F 3 "~" H 9100 1000 50  0001 C CNN
	1    9100 1000
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R11
U 1 1 5EBEF5E0
P 9100 1900
F 0 "R11" V 8904 1900 50  0000 C CNN
F 1 "100" V 8995 1900 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 9100 1900 50  0001 C CNN
F 3 "~" H 9100 1900 50  0001 C CNN
	1    9100 1900
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R10
U 1 1 5EC0FE55
P 9100 1400
F 0 "R10" V 8904 1400 50  0000 C CNN
F 1 "150" V 8995 1400 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 9100 1400 50  0001 C CNN
F 3 "~" H 9100 1400 50  0001 C CNN
	1    9100 1400
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R12
U 1 1 5EC0FFEC
P 9100 2100
F 0 "R12" V 8904 2100 50  0000 C CNN
F 1 "150" V 8995 2100 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 9100 2100 50  0001 C CNN
F 3 "~" H 9100 2100 50  0001 C CNN
	1    9100 2100
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R13
U 1 1 5EC10416
P 9100 2300
F 0 "R13" V 8904 2300 50  0000 C CNN
F 1 "150" V 8995 2300 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 9100 2300 50  0001 C CNN
F 3 "~" H 9100 2300 50  0001 C CNN
	1    9100 2300
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R19
U 1 1 5EC1069C
P 10000 2300
F 0 "R19" V 9804 2300 50  0000 C CNN
F 1 "150" V 9895 2300 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 10000 2300 50  0001 C CNN
F 3 "~" H 10000 2300 50  0001 C CNN
	1    10000 2300
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R18
U 1 1 5EC10891
P 10000 2100
F 0 "R18" V 9804 2100 50  0000 C CNN
F 1 "150" V 9895 2100 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 10000 2100 50  0001 C CNN
F 3 "~" H 10000 2100 50  0001 C CNN
	1    10000 2100
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R16
U 1 1 5EC10A84
P 10000 1400
F 0 "R16" V 9804 1400 50  0000 C CNN
F 1 "150" V 9895 1400 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 10000 1400 50  0001 C CNN
F 3 "~" H 10000 1400 50  0001 C CNN
	1    10000 1400
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R15
U 1 1 5EC10F82
P 10000 1200
F 0 "R15" V 9804 1200 50  0000 C CNN
F 1 "150" V 9895 1200 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" H 10000 1200 50  0001 C CNN
F 3 "~" H 10000 1200 50  0001 C CNN
	1    10000 1200
	0    1    1    0   
$EndComp
Wire Wire Line
	8400 2450 9650 2450
Wire Wire Line
	9600 1200 9650 1200
Wire Wire Line
	9650 1200 9650 2100
Connection ~ 9650 2450
Wire Wire Line
	9600 2100 9650 2100
Connection ~ 9650 2100
Wire Wire Line
	9650 2100 9650 2450
Wire Wire Line
	9650 2450 10500 2450
Wire Wire Line
	10800 2900 10800 600 
Wire Wire Line
	10100 2900 10800 2900
Wire Wire Line
	8300 600  10800 600 
Text Label 9750 1000 0    50   ~ 0
R
Text Label 9750 1200 0    50   ~ 0
G
Text Label 9750 1400 0    50   ~ 0
B
Wire Wire Line
	9750 1200 9900 1200
Wire Wire Line
	9900 1400 9750 1400
Wire Wire Line
	9900 1000 9750 1000
Text Label 9750 1900 0    50   ~ 0
R
Text Label 9750 2100 0    50   ~ 0
G
Text Label 9750 2300 0    50   ~ 0
B
Wire Wire Line
	9900 2300 9750 2300
Wire Wire Line
	9900 1900 9750 1900
Wire Wire Line
	9750 2100 9900 2100
Text Label 8850 1000 0    50   ~ 0
R
Text Label 8850 1200 0    50   ~ 0
G
Text Label 8850 1400 0    50   ~ 0
B
Wire Wire Line
	8850 1200 9000 1200
Wire Wire Line
	9000 1400 8850 1400
Wire Wire Line
	9000 1000 8850 1000
Text Label 8850 1900 0    50   ~ 0
R
Text Label 8850 2100 0    50   ~ 0
G
Text Label 8850 2300 0    50   ~ 0
B
Wire Wire Line
	8850 2100 9000 2100
Wire Wire Line
	9000 2300 8850 2300
Wire Wire Line
	9000 1900 8850 1900
$Comp
L Connector:Conn_01x24_Female J3
U 1 1 5EFEACB0
P 6700 4000
F 0 "J3" V 6865 3930 50  0000 C CNN
F 1 "Conn_01x24_Female" V 6774 3930 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x24_P2.54mm_Vertical" H 6700 4000 50  0001 C CNN
F 3 "~" H 6700 4000 50  0001 C CNN
	1    6700 4000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5600 4350 5600 4200
Wire Wire Line
	5700 4200 5700 4400
Wire Wire Line
	5800 4200 5800 4450
Wire Wire Line
	5900 4200 5900 4500
Wire Wire Line
	6000 4200 6000 4550
Wire Wire Line
	6100 4200 6100 4600
Wire Wire Line
	6200 4200 6200 4650
Wire Wire Line
	6300 4200 6300 4700
Wire Wire Line
	6400 4200 6400 4950
Wire Wire Line
	6500 4200 6500 4900
Wire Wire Line
	6600 4200 6600 4850
Wire Wire Line
	6700 4200 6700 4800
Wire Wire Line
	6800 4200 6800 4750
Wire Wire Line
	6900 4200 6900 4700
Wire Wire Line
	7000 4200 7000 4650
Wire Wire Line
	7100 4200 7100 4600
Wire Wire Line
	7200 4200 7200 4550
Wire Wire Line
	7300 4200 7300 4500
Wire Wire Line
	7900 4200 7900 4350
Wire Wire Line
	7900 4350 8300 4350
Wire Wire Line
	7400 4200 7400 4350
Wire Wire Line
	7500 4200 7500 4350
Wire Wire Line
	7600 4200 7600 4350
Text Label 7400 4350 1    50   ~ 0
Rin
Text Label 7500 4350 1    50   ~ 0
Gin
Text Label 7600 4350 1    50   ~ 0
Bin
Wire Wire Line
	5050 3950 5050 3750
$Comp
L power:GND #PWR012
U 1 1 5F5B09E8
P 4950 3950
F 0 "#PWR012" H 4950 3700 50  0001 C CNN
F 1 "GND" V 4955 3822 50  0000 R CNN
F 2 "" H 4950 3950 50  0001 C CNN
F 3 "" H 4950 3950 50  0001 C CNN
	1    4950 3950
	-1   0    0    1   
$EndComp
Wire Wire Line
	7800 4450 9750 4450
Wire Wire Line
	7800 4200 7800 4450
$Comp
L power:GND #PWR013
U 1 1 5F6B4F24
P 7700 4200
F 0 "#PWR013" H 7700 3950 50  0001 C CNN
F 1 "GND" V 7705 4072 50  0000 R CNN
F 2 "" H 7700 4200 50  0001 C CNN
F 3 "" H 7700 4200 50  0001 C CNN
	1    7700 4200
	1    0    0    -1  
$EndComp
$Comp
L RTC:DS3231-Module U8
U 1 1 5F72A0AA
P 5900 7550
F 0 "U8" H 5925 8175 50  0000 C CNN
F 1 "DS3231-Module" H 5925 8084 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x06_P2.54mm_Vertical" H 5900 7550 50  0001 C CNN
F 3 "" H 5900 7550 50  0001 C CNN
	1    5900 7550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 7400 3000 7550
Wire Wire Line
	3000 7550 6550 7550
Wire Wire Line
	6550 7550 6550 7450
Wire Wire Line
	6550 7450 6500 7450
Wire Wire Line
	6500 7350 6600 7350
Wire Wire Line
	6600 7350 6600 7600
Wire Wire Line
	6600 7600 2900 7600
Wire Wire Line
	2900 7600 2900 7400
Wire Wire Line
	3200 4500 3200 5250
Wire Wire Line
	7200 4550 7750 4550
Wire Wire Line
	7750 4550 7750 4650
Wire Wire Line
	7750 4650 7950 4650
Text Label 8400 4500 0    50   ~ 0
CL1
Text Label 7950 4650 0    50   ~ 0
CL2
Wire Wire Line
	1900 6000 1900 5850
Wire Wire Line
	2000 6000 2000 5850
Text Label 1900 5850 1    50   ~ 0
CL1
Text Label 2000 5850 1    50   ~ 0
CL2
Wire Wire Line
	2400 7400 2400 7500
Wire Wire Line
	2500 7400 2500 7500
Wire Wire Line
	2600 7400 2600 7500
Text Label 2400 7500 1    50   ~ 0
Rin
Text Label 2500 7500 1    50   ~ 0
Gin
Text Label 2600 7500 1    50   ~ 0
Bin
Wire Wire Line
	3000 6000 3000 5850
Wire Wire Line
	3000 5850 4400 5850
Wire Wire Line
	4400 5850 4400 7450
$Comp
L power:GND #PWR0105
U 1 1 5FB314C0
P 5250 7400
F 0 "#PWR0105" H 5250 7150 50  0001 C CNN
F 1 "GND" V 5255 7272 50  0000 R CNN
F 2 "" H 5250 7400 50  0001 C CNN
F 3 "" H 5250 7400 50  0001 C CNN
	1    5250 7400
	0    1    1    0   
$EndComp
Wire Wire Line
	5250 7400 5350 7400
Wire Wire Line
	3200 7400 3200 7500
Wire Wire Line
	3200 7500 4250 7500
Wire Wire Line
	4250 7500 4250 7200
Wire Wire Line
	4250 7200 5350 7200
$EndSCHEMATC
