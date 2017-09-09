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
