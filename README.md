# Bluetooth Low Energy jammer with 3D-printed case in usage with Arduino Nano Every
BLE (Bluetooth low energy) jammer using nRF24L01+ modules and an Arduino Nano Every combined in a 3D printed case.

## Brief overview
This repository is based on the original one by Wilson Ler (https://github.com/lws803/BLE-jammer) ,but provides a handy 3D case to house all the electronics and migrate the code (detailed commented) to the Arduino Nano Every.

## Project components
1. 1x Arduino Nano Every or Arduino Nano
2. 3x nRF24L01+ modules
3. 1x Mini-Breadboard
4. several Jumper wires
5. 1x 3D printed case

## GPIO adjustment
Arduino Nano Every:

| Function:  | Pin Name:| Wire color:|
| ---------- | -------- | ---------- |
| Power  	   | 3V3  	  |    red     |
| Ground  	 | GND      |    black   |   
| ADC0/CE    | A0       |   green    |
| ADC1/CSN   | A2       |   white    |
| ADC2/CE    | A3       |   green    |
| ADC3/CSN   | A4       |   white    |
| ADC5/SCK1  | D13      |   yellow   |
| ADC6/MISO1 | D12      |   brown    |
| ADC7/MOSI1 | D11      |   orange   |
| ADC8/CE    | A5       |   green    |
| ADC9/CSN   | A6       |   white    |


## Schematics and Images
put here 3d printed box

## nRF24L01+ module testing
The script [nRF24L01+_InspectionCode](https://github.com/Petros626/BLE-jammer/blob/master/nRF24L01%2B_InspectionCode.ino) is used to check the functionality of your nRF24L01+ modules. Generally some people had problems to run them without errors, so a good approach would be to check first your modules one by one with the expected output:

## Run the jammer
With the 

```cpp 
radio.printDetails()
``` 
function its easy to print the expected outpur for all of your three modules:
