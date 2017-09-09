/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package openomr.omr_engine;

import org.sintef.jarduino.DigitalPin;
import org.sintef.jarduino.DigitalState;
import org.sintef.jarduino.JArduino;
import org.sintef.jarduino.PinMode;
import org.sintef.jarduino.comm.Serial4JArduino;
/*
Blink
Turns on an LED on for one second, then off for one second, repeatedly.

This example code is in the public domain.
 */
class Blink extends JArduino {

    String letter;
    
    public Blink(String port, String letter) {
        super(port);
        this.letter = letter;
    }

    @Override
    protected void setup() {
        // initialize the digital pin as an output.
        // Pin 13 has an LED connected on most Arduino boards:
        pinMode(DigitalPin.PIN_13, PinMode.OUTPUT);
    }

    @Override
    protected void loop() {
        // set the LED on
        digitalWrite(DigitalPin.PIN_13, DigitalState.HIGH);
        delay(1000); // wait for a second
    
        // set the LED off
        digitalWrite(DigitalPin.PIN_13, DigitalState.LOW);
        delay(1000); // wait for a second
    }
}

