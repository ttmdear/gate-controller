EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A3 16535 11693
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
L Regulator_Linear:L7812 MV_U1
U 1 1 62417616
P 2800 1150
F 0 "MV_U1" H 2800 1392 50  0000 C CNN
F 1 "L7805" H 2800 1301 50  0000 C CNN
F 2 "" H 2825 1000 50  0001 L CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/41/4f/b3/b0/12/d4/47/88/CD00000444.pdf/files/CD00000444.pdf/jcr:content/translations/en.CD00000444.pdf" H 2800 1100 50  0001 C CNN
	1    2800 1150
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:L7805 MV_U2
U 1 1 6241B009
P 2800 1950
F 0 "MV_U2" H 2800 2192 50  0000 C CNN
F 1 "L7812" H 2800 2101 50  0000 C CNN
F 2 "" H 2825 1800 50  0001 L CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/41/4f/b3/b0/12/d4/47/88/CD00000444.pdf/files/CD00000444.pdf/jcr:content/translations/en.CD00000444.pdf" H 2800 1900 50  0001 C CNN
	1    2800 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 1150 3250 1150
Wire Wire Line
	3100 1950 3550 1950
$Comp
L Device:CP MV_C1
U 1 1 6241F25B
P 3250 1400
F 0 "MV_C1" H 3368 1446 50  0000 L CNN
F 1 "470uF" H 3368 1355 50  0000 L CNN
F 2 "" H 3288 1250 50  0001 C CNN
F 3 "~" H 3250 1400 50  0001 C CNN
	1    3250 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 1150 3250 1250
Connection ~ 3250 1150
Wire Wire Line
	3250 1150 3600 1150
Wire Wire Line
	3250 1550 3250 1600
Text GLabel 3600 1150 2    50   Input ~ 0
V5
Text GLabel 3550 1950 2    50   Input ~ 0
V12
$Comp
L MCU_Microchip_ATmega:ATmega328P-PU U?
U 1 1 62422123
P 5900 3050
F 0 "U?" H 5256 3096 50  0000 R CNN
F 1 "ATmega328P-PU" H 5256 3005 50  0000 R CNN
F 2 "Package_DIP:DIP-28_W7.62mm" H 5900 3050 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 5900 3050 50  0001 C CNN
	1    5900 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 4550 5900 4800
Text GLabel 5900 4800 3    50   Input ~ 0
GND
Text GLabel 3550 2400 2    50   Input ~ 0
GND
Wire Wire Line
	7400 3350 7650 3350
Text GLabel 7650 3350 2    50   Input ~ 0
V5
$Comp
L Switch:SW_DPST_x2 AT_SW_R
U 1 1 62437558
P 7400 2950
F 0 "AT_SW_R" H 7400 3185 50  0000 C CNN
F 1 "1" H 7400 3094 50  0001 C CNN
F 2 "" H 7400 2950 50  0001 C CNN
F 3 "~" H 7400 2950 50  0001 C CNN
	1    7400 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6500 3350 6950 3350
Wire Wire Line
	6950 3350 6950 2950
Wire Wire Line
	6950 2950 7200 2950
Connection ~ 6950 3350
Wire Wire Line
	6950 3350 7100 3350
Text GLabel 7600 2950 2    50   Input ~ 0
GND
$Comp
L Connector:Screw_Terminal_01x02 J?
U 1 1 62441037
P 9500 1300
F 0 "J?" H 9580 1292 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 9580 1201 50  0000 L CNN
F 2 "" H 9500 1300 50  0001 C CNN
F 3 "~" H 9500 1300 50  0001 C CNN
	1    9500 1300
	1    0    0    -1  
$EndComp
Text GLabel 9000 1400 0    50   Input ~ 0
GND
Text GLabel 9000 1300 0    50   Input ~ 0
AT_P2
Wire Wire Line
	9000 1300 9300 1300
Text GLabel 6650 3550 2    50   Input ~ 0
AT_RX
Text GLabel 6650 3650 2    50   Input ~ 0
AT_TX
Text GLabel 6650 3750 2    50   Input ~ 0
AT_P2
Text GLabel 6650 3850 2    50   Input ~ 0
AT_P12
Wire Wire Line
	6500 3550 6650 3550
Wire Wire Line
	6500 3650 6650 3650
Wire Wire Line
	6500 3750 6650 3750
Wire Wire Line
	6500 3850 6650 3850
Wire Wire Line
	6500 3950 6650 3950
Text GLabel 6650 3950 2    50   Input ~ 0
AT_P4
Wire Wire Line
	5900 1550 5900 1000
$Comp
L Device:CP AT_C100U
U 1 1 6245CF8B
P 5350 1200
F 0 "AT_C100U" H 4850 1150 50  0000 L CNN
F 1 "100uF" H 4950 1050 50  0000 L CNN
F 2 "" H 5388 1050 50  0001 C CNN
F 3 "~" H 5350 1200 50  0001 C CNN
	1    5350 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 1000 5350 1000
Wire Wire Line
	5350 1050 5350 1000
Connection ~ 5350 1000
Wire Wire Line
	5350 1350 5350 1500
Wire Wire Line
	5350 1500 5150 1500
Text GLabel 5150 1000 0    50   Input ~ 0
V5
Text GLabel 5150 1500 0    50   Input ~ 0
GND
$Comp
L Device:Crystal AT_XTAL
U 1 1 62469428
P 7400 2250
F 0 "AT_XTAL" V 7354 2381 50  0000 L CNN
F 1 "Crystal" V 7445 2381 50  0001 L CNN
F 2 "" H 7400 2250 50  0001 C CNN
F 3 "~" H 7400 2250 50  0001 C CNN
	1    7400 2250
	0    1    1    0   
$EndComp
Wire Wire Line
	6500 2450 7100 2450
Wire Wire Line
	7100 2450 7100 2050
Wire Wire Line
	7100 2050 7400 2050
Wire Wire Line
	7400 2050 7400 2100
Wire Wire Line
	6500 2550 7400 2550
Wire Wire Line
	7400 2550 7400 2400
$Comp
L Device:C AT_C20P1
U 1 1 6246C3F2
P 7750 2550
F 0 "AT_C20P1" V 7498 2550 50  0000 C CNN
F 1 "20pF" V 7589 2550 50  0000 C CNN
F 2 "" H 7788 2400 50  0001 C CNN
F 3 "~" H 7750 2550 50  0001 C CNN
	1    7750 2550
	0    1    1    0   
$EndComp
$Comp
L Device:C AT_C20P2
U 1 1 6246CD91
P 7750 2050
F 0 "AT_C20P2" V 7498 2050 50  0000 C CNN
F 1 "20pF" V 7589 2050 50  0000 C CNN
F 2 "" H 7788 1900 50  0001 C CNN
F 3 "~" H 7750 2050 50  0001 C CNN
	1    7750 2050
	0    1    1    0   
$EndComp
Wire Wire Line
	7400 2050 7600 2050
Connection ~ 7400 2050
Wire Wire Line
	7400 2550 7600 2550
Connection ~ 7400 2550
Wire Wire Line
	7900 2050 8050 2050
Wire Wire Line
	8050 2050 8050 2300
Wire Wire Line
	8050 2550 7900 2550
Wire Wire Line
	8050 2300 8200 2300
Connection ~ 8050 2300
Wire Wire Line
	8050 2300 8050 2550
Text GLabel 8200 2300 2    50   Input ~ 0
GND
$Comp
L Connector:Screw_Terminal_01x02 J?
U 1 1 62491CDC
P 9500 1750
F 0 "J?" H 9580 1742 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 9580 1651 50  0000 L CNN
F 2 "" H 9500 1750 50  0001 C CNN
F 3 "~" H 9500 1750 50  0001 C CNN
	1    9500 1750
	1    0    0    -1  
$EndComp
Text GLabel 9000 1850 0    50   Input ~ 0
GND
Text GLabel 9000 1750 0    50   Input ~ 0
AT_P12
Wire Wire Line
	9000 1750 9300 1750
$Comp
L Connector:Screw_Terminal_01x02 J?
U 1 1 62493076
P 9500 2200
F 0 "J?" H 9580 2192 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 9580 2101 50  0000 L CNN
F 2 "" H 9500 2200 50  0001 C CNN
F 3 "~" H 9500 2200 50  0001 C CNN
	1    9500 2200
	1    0    0    -1  
$EndComp
Text GLabel 9000 2300 0    50   Input ~ 0
GND
Text GLabel 9000 2200 0    50   Input ~ 0
AT_P4
Wire Wire Line
	9000 2200 9300 2200
$Comp
L Connector:Screw_Terminal_01x02 J?
U 1 1 6249415A
P 9500 2600
F 0 "J?" H 9580 2592 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 9580 2501 50  0000 L CNN
F 2 "" H 9500 2600 50  0001 C CNN
F 3 "~" H 9500 2600 50  0001 C CNN
	1    9500 2600
	1    0    0    -1  
$EndComp
Text GLabel 9000 2700 0    50   Input ~ 0
GND
Text GLabel 9000 2600 0    50   Input ~ 0
AT_P5
Wire Wire Line
	9000 2600 9300 2600
$Comp
L Connector:Screw_Terminal_01x02 J?
U 1 1 624955F7
P 9500 3000
F 0 "J?" H 9580 2992 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 9580 2901 50  0000 L CNN
F 2 "" H 9500 3000 50  0001 C CNN
F 3 "~" H 9500 3000 50  0001 C CNN
	1    9500 3000
	1    0    0    -1  
$EndComp
Text GLabel 9000 3100 0    50   Input ~ 0
GND
Text GLabel 9000 3000 0    50   Input ~ 0
AT_P6
Wire Wire Line
	9000 3000 9300 3000
$Comp
L Connector:Screw_Terminal_01x02 J?
U 1 1 62496816
P 9500 800
F 0 "J?" H 9580 792 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 9580 701 50  0000 L CNN
F 2 "" H 9500 800 50  0001 C CNN
F 3 "~" H 9500 800 50  0001 C CNN
	1    9500 800 
	1    0    0    -1  
$EndComp
Wire Wire Line
	9300 800  9000 800 
Wire Wire Line
	9300 900  9000 900 
Text GLabel 9000 800  0    50   Input ~ 0
AT_RX
Text GLabel 9000 900  0    50   Input ~ 0
AT_TX
$Comp
L Device:Q_NPN_BCE SW_OP_Q
U 1 1 624AAF7A
P 8900 4200
F 0 "SW_OP_Q" H 9091 4246 50  0000 L CNN
F 1 "BC337" H 9091 4155 50  0000 L CNN
F 2 "" H 9100 4300 50  0001 C CNN
F 3 "~" H 8900 4200 50  0001 C CNN
	1    8900 4200
	1    0    0    -1  
$EndComp
$Comp
L Device:R SW_OP_R
U 1 1 624AF8C3
P 8550 4200
F 0 "SW_OP_R" V 8343 4200 50  0000 C CNN
F 1 "R" V 8434 4200 50  0000 C CNN
F 2 "" V 8480 4200 50  0001 C CNN
F 3 "~" H 8550 4200 50  0001 C CNN
	1    8550 4200
	0    1    1    0   
$EndComp
Text GLabel 8400 4200 0    50   Input ~ 0
AT_P7
$Comp
L Connector:Screw_Terminal_01x02 SW_OP_SCREW
U 1 1 624B041A
P 9500 3600
F 0 "SW_OP_SCREW" H 9580 3592 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 9580 3501 50  0001 L CNN
F 2 "" H 9500 3600 50  0001 C CNN
F 3 "~" H 9500 3600 50  0001 C CNN
	1    9500 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	9300 3700 9000 3700
Wire Wire Line
	9000 3700 9000 4000
Wire Wire Line
	9000 4400 9000 4650
Text GLabel 9000 4650 3    50   Input ~ 0
GND
Wire Wire Line
	9300 3600 9000 3600
Text GLabel 9000 3600 0    50   Input ~ 0
V12
$Comp
L Device:Q_NPN_BCE SW_CL_Q
U 1 1 624C4F6D
P 8900 5600
F 0 "SW_CL_Q" H 9091 5646 50  0000 L CNN
F 1 "BC337" H 9091 5555 50  0000 L CNN
F 2 "" H 9100 5700 50  0001 C CNN
F 3 "~" H 8900 5600 50  0001 C CNN
	1    8900 5600
	1    0    0    -1  
$EndComp
Text GLabel 8400 5600 0    50   Input ~ 0
AT_P8
$Comp
L Connector:Screw_Terminal_01x02 SW_CL_SCREW
U 1 1 624C4F7A
P 9500 5000
F 0 "SW_CL_SCREW" H 9580 4992 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 9580 4901 50  0001 L CNN
F 2 "" H 9500 5000 50  0001 C CNN
F 3 "~" H 9500 5000 50  0001 C CNN
	1    9500 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	9300 5100 9000 5100
Wire Wire Line
	9000 5100 9000 5400
Wire Wire Line
	9000 5800 9000 6050
Text GLabel 9000 6050 3    50   Input ~ 0
GND
Wire Wire Line
	9300 5000 9000 5000
Text GLabel 9000 5000 0    50   Input ~ 0
V12
$Comp
L Connector:Screw_Terminal_01x02 J?
U 1 1 624CD55F
P 12050 800
F 0 "J?" H 12130 792 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 12130 701 50  0000 L CNN
F 2 "" H 12050 800 50  0001 C CNN
F 3 "~" H 12050 800 50  0001 C CNN
	1    12050 800 
	1    0    0    -1  
$EndComp
Text GLabel 11400 800  0    50   Input ~ 0
GND
Wire Wire Line
	11400 800  11850 800 
Wire Wire Line
	11850 900  11400 900 
Text GLabel 11400 900  0    50   Input ~ 0
AT_P9
$Comp
L Connector:Screw_Terminal_01x02 J?
U 1 1 624D4E6F
P 12050 1350
F 0 "J?" H 12130 1342 50  0000 L CNN
F 1 "Screw_Terminal_01x02" H 12130 1251 50  0000 L CNN
F 2 "" H 12050 1350 50  0001 C CNN
F 3 "~" H 12050 1350 50  0001 C CNN
	1    12050 1350
	1    0    0    -1  
$EndComp
Text GLabel 11400 1350 0    50   Input ~ 0
V5
Wire Wire Line
	11400 1350 11850 1350
Wire Wire Line
	11850 1450 11400 1450
Text GLabel 11400 1450 0    50   Input ~ 0
AT_P10
$Comp
L Own:RF_RX_433MHz U?
U 1 1 624D82E7
P 11850 2050
F 0 "U?" H 11900 2315 50  0000 C CNN
F 1 "RF_RX_433MHz" H 11900 2224 50  0000 C CNN
F 2 "" H 11850 2250 50  0001 C CNN
F 3 "" H 11850 2250 50  0001 C CNN
	1    11850 2050
	1    0    0    -1  
$EndComp
Text GLabel 11550 2050 0    50   Input ~ 0
GND
Text GLabel 11550 2150 0    50   Input ~ 0
AT_P11
Text GLabel 12250 2050 2    50   Input ~ 0
V5
$Comp
L Device:D MV_D1
U 1 1 624F1681
P 2350 1150
F 0 "MV_D1" H 2350 933 50  0000 C CNN
F 1 "1N4007" H 2350 1024 50  0000 C CNN
F 2 "" H 2350 1150 50  0001 C CNN
F 3 "~" H 2350 1150 50  0001 C CNN
	1    2350 1150
	-1   0    0    1   
$EndComp
Wire Wire Line
	1600 1150 2150 1150
$Comp
L Device:D MV_D2
U 1 1 624F3F18
P 2350 1950
F 0 "MV_D2" H 2350 1733 50  0000 C CNN
F 1 "1N4007" H 2350 1824 50  0000 C CNN
F 2 "" H 2350 1950 50  0001 C CNN
F 3 "~" H 2350 1950 50  0001 C CNN
	1    2350 1950
	-1   0    0    1   
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 MV_SCREW
U 1 1 62414A3C
P 1400 1250
F 0 "MV_SCREW" H 1400 1000 50  0000 C CNN
F 1 "12V" H 1318 1016 50  0001 C CNN
F 2 "" H 1400 1250 50  0001 C CNN
F 3 "~" H 1400 1250 50  0001 C CNN
	1    1400 1250
	-1   0    0    1   
$EndComp
Wire Wire Line
	2150 1950 2200 1950
Connection ~ 2150 1150
Wire Wire Line
	2150 1150 2200 1150
Wire Wire Line
	2150 1150 2150 1950
Wire Wire Line
	1600 1250 2050 1250
Wire Wire Line
	2050 1250 2050 1600
Wire Wire Line
	2800 2400 2050 2400
Wire Wire Line
	2800 2250 2800 2400
Wire Wire Line
	2800 1600 2050 1600
Wire Wire Line
	2800 1450 2800 1600
Connection ~ 2050 1600
Wire Wire Line
	2050 1600 2050 2400
Wire Wire Line
	2800 1600 3250 1600
Connection ~ 2800 1600
Wire Wire Line
	3550 2400 2800 2400
Connection ~ 2800 2400
$Comp
L Device:R AT_R1
U 1 1 6243205C
P 7250 3350
F 0 "AT_R1" V 7043 3350 50  0000 C CNN
F 1 "10k" V 7134 3350 50  0001 C CNN
F 2 "" V 7180 3350 50  0001 C CNN
F 3 "~" H 7250 3350 50  0001 C CNN
	1    7250 3350
	0    1    1    0   
$EndComp
Wire Wire Line
	5350 1000 5900 1000
Wire Wire Line
	6000 1550 6000 800 
Wire Wire Line
	6000 800  5150 800 
Text GLabel 5150 800  0    50   Input ~ 0
V5
$Comp
L Device:R SW_CL_Q
U 1 1 624C4F73
P 8550 5600
F 0 "SW_CL_Q" V 8343 5600 50  0000 C CNN
F 1 "R" V 8434 5600 50  0000 C CNN
F 2 "" V 8480 5600 50  0001 C CNN
F 3 "~" H 8550 5600 50  0001 C CNN
	1    8550 5600
	0    1    1    0   
$EndComp
Text GLabel 6650 4050 2    50   Input ~ 0
AT_P5
Text GLabel 6650 4150 2    50   Input ~ 0
AT_P6
Wire Wire Line
	6500 4050 6650 4050
Wire Wire Line
	6500 4150 6650 4150
Text GLabel 6650 4250 2    50   Input ~ 0
AT_P7
Wire Wire Line
	6500 4250 6650 4250
Text GLabel 6650 1850 2    50   Input ~ 0
AT_P8
Wire Wire Line
	6650 1850 6500 1850
Text GLabel 6650 1950 2    50   Input ~ 0
AT_P9
Text GLabel 6650 2050 2    50   Input ~ 0
AT_P10
Wire Wire Line
	6500 1950 6650 1950
Wire Wire Line
	6500 2050 6650 2050
Text GLabel 6650 2150 2    50   Input ~ 0
AT_P11
Wire Wire Line
	6500 2150 6650 2150
Wire Wire Line
	6500 2350 7050 2350
Wire Wire Line
	7050 2350 7050 1500
Wire Wire Line
	7050 1500 7400 1500
$Comp
L Device:LED D?
U 1 1 6246F5BE
P 7550 1500
F 0 "D?" H 7543 1245 50  0000 C CNN
F 1 "LED" H 7543 1336 50  0000 C CNN
F 2 "" H 7550 1500 50  0001 C CNN
F 3 "~" H 7550 1500 50  0001 C CNN
	1    7550 1500
	-1   0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 62470486
P 7950 1500
F 0 "R?" V 7743 1500 50  0000 C CNN
F 1 "1k" V 7834 1500 50  0000 C CNN
F 2 "" V 7880 1500 50  0001 C CNN
F 3 "~" H 7950 1500 50  0001 C CNN
	1    7950 1500
	0    1    1    0   
$EndComp
Wire Wire Line
	7700 1500 7800 1500
Text GLabel 8200 1500 2    50   Input ~ 0
GND
Wire Wire Line
	8100 1500 8200 1500
Wire Wire Line
	9000 1400 9300 1400
Wire Wire Line
	9000 1850 9300 1850
Wire Wire Line
	9000 2300 9300 2300
Wire Wire Line
	9000 2700 9300 2700
Wire Wire Line
	9000 3100 9300 3100
$EndSCHEMATC
