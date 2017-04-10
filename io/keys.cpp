/* A Simple GPIO application
*  Written by Derek Molloy for the book "Exploring Raspberry Pi" */

#include <iostream>
#include <unistd.h>  // for the usleep() function
#include "GPIO.h"
#include "keys.h"
using namespace exploringRPi;
using namespace std;


int main(){
   GPIO out[5] = {GPIO(LED1), GPIO(LED2), GPIO(LED3), GPIO(LED4), GPIO(LED5)};
   GPIO in[3] = {GPIO(BTN1), GPIO(BTN2),GPIO(BTN3)};

   for(int i = 0; i < 5; i++)
   	out[i].setDirection(OUTPUT);
   for(int i = 0; i < 3; i++)
   	in[i].setDirection(INPUT);

   for (int i=0; i<100; i++){        // flash the LED 10 times
   		for(int j = 0; j < 5; j++)
      		out[i].setValue(HIGH);       // turn the LED on
      usleep(50000);               // sleep for 0.5 seconds
   		for(int j = 0; j < 5; j++)
      		out[i].setValue(LOW);       // turn the LED on
      usleep(50000);               // sleep for 0.5 seconds
   }



   // inGPIO.setDirection(INPUT);      // basic input example
   // cout << "The input state is: "<< inGPIO.getValue() << endl;

   // outGPIO.streamOpen();            // fast write example
   // for (int i=0; i<1000000; i++){   // write 1 million cycles
   //    outGPIO.streamWrite(HIGH);    // high
   //    outGPIO.streamWrite(LOW);     // immediately low, repeat
   // }
   // outGPIO.streamClose();           // close the stream
   return 0;
}
