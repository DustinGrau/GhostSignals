/**
 *   Haslab Ghost Trap Signalling Library
 *   Maintained by Dustin Grau <dustin.grau@gmail.com>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, see <https://www.gnu.org/licenses/>.
 *
 */

// https://github.com/Arduino-IRremote/Arduino-IRremote
#include <IRremote.hpp>

// Define the IR LED pin (D9 which has PWM)
const int irLedPin = 9;

#define LED_BUILTIN 13
#define SIGNAL_KHZ 38
#define DELAY_AFTER_SEND 5000

// Send a similar signal as captured from the PKE device at full power
const uint16_t irSignal[] = {
    1774, 1178, 612, 612, 581, 612, 581, 1184, 
    606, 612, 581, 1209, 581, 1209, 581, 612, 
    581, 1182, 608
};

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);

    Serial.begin(115200);

    // Initialize the IR LED pin
    IrSender.begin(irLedPin);
}

void loop() {
    // Send the raw IR data
    digitalWrite(LED_BUILTIN, HIGH); // Turn LED on
    IrSender.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), SIGNAL_KHZ);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW); // Turn LED off

    // Wait before sending the signal again
    delay(DELAY_AFTER_SEND);
}
