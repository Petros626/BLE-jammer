/*
  If your serial output has these values same then Your nrf24l01 module is in working condition :
  
  EN_AA          = 0x3f
  EN_RXADDR      = 0x02
  RF_CH          = 0x4c
  RF_SETUP       = 0x03
  CONFIG         = 0x0f
  
  This code is under public domain
  
  Last updated on 23/01/19
  revised by Petros K. 
  https://dhirajkushwaha.com/elekkrypt
 */

#include <SPI.h>
#include <RF24.h>
#include <printf.h>

// select your CE & CSN Pins <-- Configure here FIRST
RF24 radio(A0, A1);

byte addresses[][6] = {"1Node", "2Node"};


void setup() 
{
/**************************************************************
*	Name:		radio(), radio2(), radio3()
*	Func:		Constructor, Creates a new instance of this driver. 
Before using, you create an instance and send in the 
unique pins that this chip is connected to.
*	Return:	nothing
*************************************************************/
  radio.begin();


/*****************************************************
*	Name:		setPALevel()
*	Func:		Set Power Amplifier (PA) level and Low Noise 
Amplifier (LNA) state
*	Return:	nothing
*****************************************************/
  radio.setPALevel(RF24_PA_LOW);
  

/*********************************************
*	Name:		openWritingPipe()
*	Func:	  Open a pipe for writing via byte array.
*	Return:	nothing
*********************************************/
  radio.openWritingPipe(addresses[0]);


/*********************************************
*	Name:		openReadingPipe()
*	Func:	  Open a pipe for reading.
*	Return:	nothing
*********************************************/ 
  radio.openReadingPipe(1, addresses[1]);


/*********************************************
*	Name:		startListening()
*	Func:	  Start listening on the pipes 
opened for reading.
*	Return:	nothing
*********************************************/ 
  radio.startListening();
  
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
  printf("\nnRF24L01+ module:\n\n");
  radio.printDetails();
  
  
}

void loop() {
//  empty

}
