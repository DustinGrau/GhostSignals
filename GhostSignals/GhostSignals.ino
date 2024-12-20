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
#include <IRremote.h>

// Define the IR LED pin
const int irLedPin = 3;

// Raw data from PKE device
const unsigned int rawData[] = {
    1774, 1178, 612, 612, 581, 612, 581, 1184, 
    606, 612, 581, 1209, 581, 1209, 581, 612, 
    581, 1182, 608
};

void setup() {
    // Initialize the IR LED pin
    IrSender.begin(irLedPin, ENABLE_LED_FEEDBACK);
}

void loop() {
    // Send the raw IR data
    IrSender.sendRaw(rawData, sizeof(rawData) / sizeof(rawData[0]), 38);

    // Wait before sending the signal again
    delay(5000); // Adjust the delay as needed
}
