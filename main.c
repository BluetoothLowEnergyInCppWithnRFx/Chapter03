#include "mbed.h"
#include "ble/BLE.h"

/** User interface I/O **/

// instantiate USB Serial
Serial serial(USBTX, USBRX);

// Status LED
DigitalOut statusLed(LED1, 0);

// Timer for blinking the statusLed
Ticker ticker;

/** Functions **/

/**
 * visually signal that program has not crashed
 */
void blinkHeartbeat(void);

/**
 * Main program and loop
 */
int main(void) {
    serial.baud(9600);
    serial.printf("Hello World\r\n");

    ticker.attach(blinkHeartbeat, 1);

    while (1) {
        serial.printf(".");
        wait(1);
    }
}

void blinkHeartbeat(void) {
    statusLed = !statusLed; /* Do blinky on LED1 to indicate system aliveness. */
}