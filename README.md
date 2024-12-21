# Ghost Signals

Provide a means of triggering the ghost sounds from the Haslab Ghost Trap using infrared signals. Requires an Arduino Nano with an IR LED using the "IRremote" library.

![](Images/Overview.jpg)

## How It Works

When the Haslab PKE Meter is set to full power (wings fully up) there is a single pulse of IR data sent from an LED behind the taser lens. See a video of this by use of a full-spectrum camera using a 980nm IR filter: [IR Blast](Video/IR_Blast.mp4)

To capture the signal, a Flipper Zero was used to record the IR signal from the PKE as a "remote". The resulting data consists of a 38kHz carrier frequency a total of 19 pulses for the signaling. Replaying the signal proved there is no obvious variation in the data, meaning a single command triggers the ghost sounds every time: [Proof of Concept](Video/POC.mp4)

## Bill of Materials

* Microcontroller (Arduino Nano)
* 1x IR LED
* 1x Resistor (180ohm or 220ohm)

### Assembly

1. Put the resistor on the anode (+) leg of the LED and tie to pin D9
1. Attach the cathode (-) of the LED to GND on the microcontroller
1. Load the Arduini sketch in the `GhostSignals` folder

That's it! The current software will simply pulse the signal every 5 seconds. Do what you will with this information in your projects!