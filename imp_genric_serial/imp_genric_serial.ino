/*
Arduino UART

Arduino firmware for imp -> arduino UART.

License:
BSD-3 Clause

Author:
Calum Barnes, Xively Systems Enginer, November 2013

*/
#include <SoftwareSerial.h>

SoftwareSerial impSerial(8, 9); // RX on 8, TX on 9

char inData[100]; 
char inChar=-1; 
byte index = 0; 
String input = "";
boolean newdata = false;



void setup(){
  Serial.begin(19200);
  
  impSerial.begin(19200);
  
  Serial.println("==STARTING==");
}//end setup

void loop(){
  while (impSerial.available() > 0){

            inChar = impSerial.read(); // Read a character
            inData[index] = inChar; // Store it
            index++; // Increment where to write next
            inData[index] = '\0'; // Null terminate the string  
            Serial.print(inChar);
            newdata = true;
    }
    
    index = 0;
    
  
    if(newdata){ 
      Serial.println("new data");
       if(inData[0] == 'X'){
           int i = 1;
          while(inData[i] != 'Q'){
             input.concat(inData[i]);
             i++;
          } 
       }
       Serial.println(input);
       
       newdata = false;
       input = "";
    }
    

}//end loop


/////////////////////////////FUNCTIONS///////////////////////////////////
//custom function to parse values from accell to number of leds

