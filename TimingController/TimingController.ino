/*
Engine coil-on-plug controller
by Olavi, 6 Aug 2017
 */

#include "SignalIn.h"
#define SPARK 13 //pin number for spark output
#define SENSOR 2 //pin number for sensor input
SignalIn camSignal(SENSOR, SPARK);

 // the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.

  pinMode(SPARK, OUTPUT);
  pinMode(SENSOR, INPUT); //square hall/vr signal  

  attachInterrupt(digitalPinToInterrupt(SENSOR), callSpark, RISING);

}

// the loop function runs over and over again forever
void loop() {
}

void callSpark(){ //helper to call member function
	  camSignal.makeSpark(); 
}
