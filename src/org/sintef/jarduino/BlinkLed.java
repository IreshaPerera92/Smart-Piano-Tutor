
package org.sintef.jarduino;

import java.util.Timer;
import java.util.TimerTask;
import java.util.logging.Level;
import java.util.logging.Logger;

import org.sintef.jarduino.DigitalPin;
import org.sintef.jarduino.DigitalState;
import org.sintef.jarduino.InterruptTrigger;
import org.sintef.jarduino.JArduino;
import org.sintef.jarduino.PinMode;
import org.sintef.jarduino.InterruptPin;

/*import org.jivesoftware.smack.ConnectionConfiguration;
import org.jivesoftware.smack.PacketListener;
import org.jivesoftware.smack.XMPPConnection;
import org.jivesoftware.smack.XMPPException;
import org.jivesoftware.smack.packet.Message;
import org.jivesoftware.smack.packet.Packet;
import org.jivesoftware.smack.packet.Presence;*/

public class BlinkLed extends JArduino {

    private DigitalPin led;
    
    private Timer timer;
   
    public BlinkLed(String port) {
        super(port);
		 this.timer = new Timer();
    }

    /**
     * When button is clicked, sends a message to your friend
     *
     * @param interrupt
     */

    public void turnOffLED(DigitalPin led) {
        digitalWrite(led, DigitalState.LOW);
        System.out.println("Hopefully, the LED should now be turned OFF");
    }

    public void turnOnLED(DigitalPin led) {
        digitalWrite(led, DigitalState.HIGH);
        System.out.println("Hopefully, the LED should now be turned ON");
    }

    public void turnOnLEDfor(long delay,DigitalPin led) {
        turnOnLED(led);
        timer.schedule(new Timeout(), delay);
    }

    @Override
    protected void setup() {
        pinMode(led, PinMode.OUTPUT);
    }

    @Override
    protected void loop() {
    }

    private class Timeout extends TimerTask {

        @Override
        public void run() {
            turnOffLED(led);
        }
    }

    /**
     * Please set the serial port with the proper port, the credentials of your
     * Google Account, as well as the PIN where your LED is connected on your
     * Arduino board. Disclaimer: We are not responsible for any troubles with
     * your google account. The connection to your Google account is entirely
     * delegated to the Smack API
     */
    public static void main(String[] args) {
    
        String serialPort = "COM3";

        DigitalPin led = DigitalPin.PIN_13;


        BlinkLed arduino = new BlinkLed(serialPort);
        arduino.runArduinoProcess();
		arduino.turnOnLED(led);
		arduino.turnOffLED(led);
                arduino.turnOnLED(led);
                arduino.turnOffLED(led);
                
    }
}
