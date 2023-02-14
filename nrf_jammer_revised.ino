/*
* Arduino nRF24L01+ Noise Gen
*                
* by Wilson
* revised by Petros
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
* Documentation: https://nrf24.github.io/RF24/index.html
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <printf.h>

// define LED
const int D13 = 13;
/**************************************************************
*	Name:		radio(), radio2(), radio3()
*	Func:		Constructor, Creates a new instance of this driver. 
Before using, you create an instance and send in the 
unique pins that this chip is connected to.
*	Return:	nothing
*************************************************************/
RF24 radio(A0,A1); // Pins from Nano Every for CE (PD3) & CSN (PD2) Pin of first nRF24L01+ module
RF24 radio2(A2,A3); // (PD1), (PD0) see above (second nRF24L01+ module)
RF24 radio3(A5,A6); // (PA3), (PD4) see above (third nRF24L01+ module)

void setup() 
{
  // set PE2 (D13) LED Pin as output
  pinMode(D13,OUTPUT);

/************************************************
*	Name:		begin()
*	Func:		Begin operation of the chip. Set the SPI
				pins MISO, MOSI and SCK.
*	Return:	bool: true = successful, false = failed
************************************************/
  radio.begin();
  radio2.begin();
  radio3.begin();

/******************************
*	Name:		powerDown()
*	Func:		Enter low-power mode.
*	Return:	nothing
******************************/
  radio.powerDown();
  radio2.powerDown();
  radio3.powerDown();
  
  // take 1s
  delay(1000);
  // turn off LED
  digitalWrite(D13,LOW);

/*first nRF24L01+*/
/*************************************************************
*	Name:		powerUp()
*	Func:		Leave low-power mode - 
required for normal radio operation after calling powerDown().
*	Return:	nothing
*************************************************************/
  radio.powerUp();

/******************************************************************
*	Name:		setAutoAck()
*	Func:		Enable (true) or disable (false) the auto-acknowledgement 
feature for all pipes.
*	Return:	nothing
******************************************************************/
  radio.setAutoAck(false);

/*****************************************************
*	Name:		setPALevel()
*	Func:		Set Power Amplifier (PA) level and Low Noise 
Amplifier (LNA) state
*	Return:	nothing
*****************************************************/
  radio.setPALevel(RF24_PA_HIGH);

/************************************************
*	Name:		setDataRate()
*	Func:		How fast data moves through the air. 
Units are in bits per second (bps).
*	Return:	bool: true = successful, false = failed
************************************************/
  radio.setDataRate(RF24_2MBPS);

/*********************************************
*	Name:		stopListening()
*	Func:	  Stop listening for incoming messages
, and switch to transmit mode.
*	Return:	nothing
*********************************************/
  radio.stopListening();

/*********************************************
*	Name:		setChannel()
*	Func:	  Set RF communication channel. 
The frequency used by a channel is calculated as:
2400 MHz + <channel number>.

BLE Channel Number | Frequency Value
37 -> 2402 MHz = 2400 MHz + 2
38 -> 2426 MHz = 2400 MHz + 26
39 -> 2480 MHz = 2400 MHz + 80
*	Return:	nothing
*********************************************/
  radio.setChannel(2); // 2402 MHz
  delay(1000);

  // second nRF24L01+ (for info see above)
  radio2.powerUp();
  radio2.setAutoAck(false);
  radio2.setPALevel(RF24_PA_HIGH);
  radio2.setDataRate(RF24_2MBPS);
  radio2.stopListening();
  radio2.setChannel(26); // 2426 MHz
  delay(1000);

  // third nRF24L01+ (for info see above)
  radio3.powerUp();
  radio3.setAutoAck(false);
  radio3.setPALevel(RF24_PA_HIGH);
  radio3.setDataRate(RF24_2MBPS);
  radio3.stopListening();
  radio3.setChannel(80); // 2480 MHz
  delay(1000);

  // turn on LED
  digitalWrite(D13,HIGH);
  
  // Sets the data rate in bits per second (baud) for serial data transmission
  Serial.begin(9600);
  // print nRF24L01+ details
  printf_begin();

/*********************************************
*	Name:	  printDetails()
*	Func:	  Print a giant block of debugging 
information to stdout
*	Return:	nothing
*********************************************/
  printf("\nnRF24L01 module 1:\n\n");
  radio.printDetails();
  printf("\nnRF24L01 module 2:\n\n");
  radio2.printDetails();
  printf("\nnRF24L01 module 3:\n\n");
  radio3.printDetails();
  
}

void loop() 
{
  // random string for spaming the three channels
  // uint8_t = byte (original code using byte, but char also works)
  char spam[] = {"x"};

  /****************************************
  *	Name:		writeFast()
  *	Func:		writes PayLoad to the buffers
  *	Return:	int: 0 = failed, 1 = successful
  ****************************************/
  radio.writeFast(&spam, sizeof(spam)); // call by address
  radio2.writeFast(&spam, sizeof(spam));
  radio3.writeFast(&spam, sizeof(spam));
 
  
  

}
