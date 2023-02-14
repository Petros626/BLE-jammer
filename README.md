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
6. 4x M3 thread insert

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
The script [nRF24L01+_InspectionCode](https://github.com/Petros626/BLE-jammer/blob/master/nRF24L01%2B_InspectionCode.ino) is used to check the functionality of your nRF24L01+ modules. Generally some people had problems to run them without errors, so a good approach would be to check first your modules **one by one** with the expected output:
```
nRF24L01+ module:
```
```
EN_AA	= 0x3f
EN_RXADDR	= 0x02
RF_CH	= 0x4c
RF_SETUP = 0x03
CONFIG	= 0x0f
``` 

## Run the jammer
With the 

```ruby
printDetails(); 
``` 
function (https://nrf24.github.io/RF24/classRF24.html#adc95213ed4c8569a90eb33122e16cea6) it's easy to print the expected output for all of your three modules. It should similiar to this, after your powered up the Arduino and every wire connection is in the right place:
```
nRF24L01 module :

EN_AA	= 0x00
EN_RXADDR	= 0x03
RF_CH	= 0x02
RF_SETUP = 0x0d
CONFIG = 0x0e
```
```
nRF24L01 module 2:

EN_AA		= 0x0
EN_RXADDR	= 0x03
RF_CH		= 0x1a
RF_SETUP	= 0x0d
CONFIG		= 0x0e
```
```
nRF24L01 module 3:

EN_AA		= 0x00
EN_RXADDR	= 0x03
RF_CH		= 0x50
RF_SETUP	= 0x0d
CONFIG		= 0x0e
```

# Outlook
As the author has already described, this jammer is used to block device detection; with devices that are already known, the jammer will probably have no effect. This requires a jammer that covers the entire frequency range of Bluetooth Low Energy.

A product that I bought and tested successfully:

![image](https://user-images.githubusercontent.com/62354721/218671915-bdee305a-c6d1-4482-8390-806c67b2abae.png)

https://de.aliexpress.com/item/1005003664010447.html?spm=a2g0o.order_list.order_list_main.11.59c15c5f3fmlqw&gatewayAdapt=glo2deu

I reccommend to buy this antenna (male connector is needed) too, because the default one has a poor range:

https://de.aliexpress.com/item/32978207284.html?spm=a2g0o.order_list.order_list_main.5.59c15c5f3fmlqw&gatewayAdapt=glo2deu


