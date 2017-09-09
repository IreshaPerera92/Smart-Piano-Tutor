const int ledPin1 = 1; // the pin that the LED is attached to
const int ledPin2 = 2;
const int ledPin3 = 3;
const int ledPin4 = 4;
const int ledPin5 = 5;
const int ledPin6 = 6;
const int ledPin7 = 7; 
 
int pin, blinkTime;
String a;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPin1, OUTPUT);
   pinMode(ledPin2, OUTPUT);
    pinMode(ledPin3, OUTPUT);
   pinMode(ledPin4, OUTPUT);
   pinMode(ledPin5, OUTPUT);
   pinMode(ledPin6, OUTPUT);
   pinMode(ledPin7, OUTPUT);
}

void loop() {
  // see if there's incoming serial data:
  if (Serial.available() > 0) {
    
    // read the string from serial line
    a=Serial.readString();
    char Buf[50];
    a.toCharArray(Buf, 50);
    int i = 0;
    char* delims = { "_ ," };
    char *p = strtok (Buf, delims);
    char *array[50];
    int arrSize = sizeof( array ) / sizeof( int );
    
   
    while (p != NULL)
    {
        array[i++] = p;
        p = strtok (NULL, delims);
    }

    //for(int a=0;a<50;a++){Serial.println( array[a]);}

    int c=0;
    while( c < 15){ 
        //Serial.print( *array[c]);
        pin=*array[c]-'0';
        //Serial.print(":");
        blinkTime=*array[++c]-'0';
        //Serial.print(*array[c]);
        
        
        Serial.print("PinN:");
        Serial.println( pin);
        //c++;
        Serial.print("Brate:");
        
        Serial.println( blinkTime);  

        digitalWrite(pin, HIGH);
        delay(blinkTime*1000);
        digitalWrite(pin, LOW);
         
//        c++;
//        if ( pin== 12) {
//            digitalWrite(ledPin1, HIGH);
//            delay(blinkTime*1000);
//    }
//    else if (pin == 13){
//            digitalWrite(ledPin2, HIGH);
//            delay(blinkTime*1000);
//    }
//    else if (pin == 14){
//            digitalWrite(ledPin3, HIGH);
//            delay(blinkTime*1000);
//    }
//    else if (pin == 15){
//            digitalWrite(ledPin4, HIGH);
//            delay(blinkTime*1000);
//    }
    }
}
  
}

/* Processing code for this example

 // mouseover serial

 // Demonstrates how to send data to the Arduino I/O board, in order to
 // turn ON a light if the mouse is over a square and turn it off
 // if the mouse is not.

 // based on examples by Casey Reas and Hernando Barragan





 import processing.serial.*;

 float boxX;
 float boxY;
 int boxSize = 20;
 boolean mouseOverBox = false;

 Serial port;

 void setup() {
 size(200, 200);
 boxX = width/2.0;
 boxY = height/2.0;
 rectMode(RADIUS);

 // List all the available serial ports in the output pane.
 // You will need to choose the port that the Arduino board is
 // connected to from this list. The first port in the list is
 // port #0 and the third port in the list is port #2.
 // if using Processing 2.1 or later, use Serial.printArray()
 println(Serial.list());

 // Open the port that the Arduino board is connected to (in this case #0)
 // Make sure to open the port at the same speed Arduino is using (9600bps)
 port = new Serial(this, Serial.list()[0], 9600);

 }

 void draw()
 {
 background(0);

 // Test if the cursor is over the box
 if (mouseX > boxX-boxSize && mouseX < boxX+boxSize &&
 mouseY > boxY-boxSize && mouseY < boxY+boxSize) {
 mouseOverBox = true;
 // draw a line around the box and change its color:
 stroke(255);
 fill(153);
 // send an 'H' to indicate mouse is over square:
 port.write('H');
 }
 else {
 // return the box to it's inactive state:
 stroke(153);
 fill(153);
 // send an 'L' to turn the LED off:
 port.write('L');
 mouseOverBox = false;
 }

 // Draw the box
 rect(boxX, boxY, boxSize, boxSize);
 }


 */



