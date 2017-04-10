/* A Simple GPIO application
*  Written by Derek Molloy for the book "Exploring Raspberry Pi" */

#include <iostream>
#include <unistd.h>  // for the usleep() function
#include "GPIO.h"
#include "keys.h"
using namespace exploringRPi;
using namespace std;

int main(){
   GPIO out1(LED1),out2(LED2),out3(LED3),out4(LED4),out5(LED5);
   GPIO in1(BTN1),in2(BTN2),in3(BTN3);

   out1.setDirection(OUTPUT);
   out2.setDirection(OUTPUT);
   out3.setDirection(OUTPUT);
   out4.setDirection(OUTPUT);
   out5.setDirection(OUTPUT);
   in1.setDirection(INPUT);
   in2.setDirection(INPUT);
   in3.setDirection(INPUT);

   // for(int i = 0; i < 5; i++)
   // 	out[i].setDirection(OUTPUT);
   // for(int i = 0; i < 3; i++)
   // 	in[i].setDirection(INPUT);

   for (int i=0; i<100; i++){        // flash the LED 10 times		
      out1.setValue(HIGH);       // turn the LED on
      out2.setValue(HIGH);       // turn the LED on
      out3.setValue(HIGH);       // turn the LED on
      out4.setValue(HIGH);       // turn the LED on
      out5.setValue(HIGH);       // turn the LED on
      usleep(50000);               // sleep for 0.5 seconds
      out1.setValue(LOW);       // turn the LED on
      out2.setValue(LOW);       // turn the LED on
      out3.setValue(LOW);       // turn the LED on
      out4.setValue(LOW);       // turn the LED on
      out5.setValue(LOW);       // turn the LED on
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
