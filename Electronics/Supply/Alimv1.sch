EESchema Schematic File Version 4
EELAYER 30 0
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
L Regulator_Linear:LM7805_TO220 U?
U 1 1 5E787AFF
P 4800 3600
F 0 "U?" H 4800 3842 50  0000 C CNN
F 1 "LM7805_TO220" H 4800 3751 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 4800 3825 50  0001 C CIN
F 3 "http://www.fairchildsemi.com/ds/LM/LM7805.pdf" H 4800 3550 50  0001 C CNN
	1    4800 3600
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x04 J?
U 1 1 5E78C42D
P 1800 1950
F 0 "J?" H 1880 1942 50  0000 L CNN
F 1 "Screw_Terminal_01x04" H 1880 1851 50  0000 L CNN
F 2 "" H 1800 1950 50  0001 C CNN
F 3 "~" H 1800 1950 50  0001 C CNN
	1    1800 1950
	-1   0    0    1   
$EndComp
Wire Wire Line
	2150 1950 2150 1850
Wire Wire Line
	2000 1950 2150 1950
Wire Wire Line
	2000 1850 2150 1850
Wire Wire Line
	2000 2050 3200 2050
Wire Wire Line
	2000 1750 3350 1750
Text Label 3350 2050 0    50   ~ 0
GNDDRV
Text Label 3350 1750 0    50   ~ 0
VccDRV
$Comp
L power:GND #PWR?
U 1 1 5E79C1D1
P 3200 2050
F 0 "#PWR?" H 3200 1800 50  0001 C CNN
F 1 "GND" H 3205 1877 50  0000 C CNN
F 2 "" H 3200 2050 50  0001 C CNN
F 3 "" H 3200 2050 50  0001 C CNN
	1    3200 2050
	1    0    0    -1  
$EndComp
Connection ~ 3200 2050
Wire Wire Line
	3200 2050 3350 2050
$Comp
L power:+9V #PWR?
U 1 1 5E79D014
P 3550 3700
F 0 "#PWR?" H 3550 3550 50  0001 C CNN
F 1 "+9V" H 3565 3873 50  0000 C CNN
F 2 "" H 3550 3700 50  0001 C CNN
F 3 "" H 3550 3700 50  0001 C CNN
	1    3550 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 3600 3700 3600
Wire Wire Line
	3550 3700 3550 4200
Wire Wire Line
	3550 4200 4200 4200
Wire Wire Line
	4800 4200 4800 3900
Wire Wire Line
	4800 4200 5350 4200
Connection ~ 4800 4200
Wire Wire Line
	5100 3600 5350 3600
$Comp
L power:GND #PWR?
U 1 1 5E7A0461
P 4800 4200
F 0 "#PWR?" H 4800 3950 50  0001 C CNN
F 1 "GND" H 4805 4027 50  0000 C CNN
F 2 "" H 4800 4200 50  0001 C CNN
F 3 "" H 4800 4200 50  0001 C CNN
	1    4800 4200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5E7A1279
P 4200 3750
F 0 "C?" H 4315 3796 50  0000 L CNN
F 1 "0.33µF" H 4315 3705 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 4238 3600 50  0001 C CNN
F 3 "~" H 4200 3750 50  0001 C CNN
	1    4200 3750
	1    0    0    -1  
$EndComp
Connection ~ 4200 3600
Wire Wire Line
	4200 3600 4500 3600
$Comp
L Device:C C?
U 1 1 5E7A1FB0
P 5350 3750
F 0 "C?" H 5465 3796 50  0000 L CNN
F 1 "0.1µF" H 5465 3705 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5388 3600 50  0001 C CNN
F 3 "~" H 5350 3750 50  0001 C CNN
	1    5350 3750
	1    0    0    -1  
$EndComp
Connection ~ 5350 3600
Wire Wire Line
	5350 3600 5650 3600
Wire Wire Line
	4200 3900 4200 4200
Connection ~ 4200 4200
Wire Wire Line
	4200 4200 4800 4200
Wire Wire Line
	5350 3900 5350 4200
Connection ~ 5350 4200
Wire Wire Line
	5350 4200 5650 4200
$Comp
L Diode:1N4007 D?
U 1 1 5E7A40A6
P 3850 3600
F 0 "D?" H 3850 3384 50  0000 C CNN
F 1 "1N4007" H 3850 3475 50  0000 C CNN
F 2 "Diode_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 3850 3425 50  0001 C CNN
F 3 "http://www.vishay.com/docs/88503/1n4001.pdf" H 3850 3600 50  0001 C CNN
	1    3850 3600
	-1   0    0    1   
$EndComp
Wire Wire Line
	4000 3600 4200 3600
$Comp
L Connector:Conn_01x01_Male J?
U 1 1 5E7A7014
P 3350 3600
F 0 "J?" H 3458 3781 50  0000 C CNN
F 1 "Conn_01x01_Male" H 3458 3690 50  0000 C CNN
F 2 "" H 3350 3600 50  0001 C CNN
F 3 "~" H 3350 3600 50  0001 C CNN
	1    3350 3600
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Male J?
U 1 1 5E7A7FCD
P 3350 4200
F 0 "J?" H 3458 4381 50  0000 C CNN
F 1 "Conn_01x01_Male" H 3458 4290 50  0000 C CNN
F 2 "" H 3350 4200 50  0001 C CNN
F 3 "~" H 3350 4200 50  0001 C CNN
	1    3350 4200
	1    0    0    -1  
$EndComp
Connection ~ 3550 4200
$Comp
L Connector:Conn_01x01_Male J?
U 1 1 5E7A989B
P 5850 4200
F 0 "J?" H 5822 4132 50  0000 R CNN
F 1 "Conn_01x01_Male" H 5822 4223 50  0000 R CNN
F 2 "" H 5850 4200 50  0001 C CNN
F 3 "~" H 5850 4200 50  0001 C CNN
	1    5850 4200
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J?
U 1 1 5E7AB868
P 5850 3600
F 0 "J?" H 5822 3532 50  0000 R CNN
F 1 "Conn_01x01_Male" H 5822 3623 50  0000 R CNN
F 2 "" H 5850 3600 50  0001 C CNN
F 3 "~" H 5850 3600 50  0001 C CNN
	1    5850 3600
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J?
U 1 1 5E7ACAB9
P 3550 1750
F 0 "J?" H 3522 1682 50  0000 R CNN
F 1 "Conn_01x01_Male" H 3522 1773 50  0000 R CNN
F 2 "" H 3550 1750 50  0001 C CNN
F 3 "~" H 3550 1750 50  0001 C CNN
	1    3550 1750
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x01_Male J?
U 1 1 5E7ADAB9
P 3550 2050
F 0 "J?" H 3522 1982 50  0000 R CNN
F 1 "Conn_01x01_Male" H 3522 2073 50  0000 R CNN
F 2 "" H 3550 2050 50  0001 C CNN
F 3 "~" H 3550 2050 50  0001 C CNN
	1    3550 2050
	-1   0    0    1   
$EndComp
$EndSCHEMATC
