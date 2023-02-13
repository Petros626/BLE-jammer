# Bluetooth Low Energy jammer with 3D-printed case in usage with Arduino Nano Every
BLE (Bluetooth low energy) jammer using nRF24L01+ modules and an Arduino Nano Every combined in a 3D printed case.

## Brief overview
This repository is based on the original one by Wilson Ler (thanks @lws803) ,but provides a handy 3D case to house all the electronics and migrate the code (detailed commented) to the Arduino Nano Every.
## Project components
1. 1x Arduino Nano Every or Arduino Nano
2. 3x nRF24L01+ modules
3. 1x Mini-Breadboard

## GPIO adjustment

Function:		STM32 BluePill:			  Arduino Nano Every:

				     Pin Name				      Pin Name

Power			   3.3		     ->		    3.3
Ground			 GND		     ->		    GND
ADC0/CE		   (PA0)A0	   ->		   (PD3)A0
ADC1/CSN	   (PA1)A1	   ->		   (PD2)A1
ADC2/CE		   (PA2)A2	   ->		   (PD1)A2
ADC3/CSN	   (PA3)A3	   ->		   (PD0)A3

ADC5/SCK1	   (PA5)A5	   ->	 	   (PE2)D13		
ADC6/MISO1	 (PA6)A6	   ->		   (PE1)D12	
ADC7/MOSI1	 (PA7)A7     ->		   (PE0)D11
	
ADC8/CE		   (PB0)B0	   ->		   (PA3)A5	
ADC9/CSN	   (PB1)B1	   ->		   (PD4)A6

## Schematics ad Images

