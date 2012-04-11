#include <avr/io.h>

const uint8_t LED = PB0;
const uint8_t BTN = PB1;

int main() {
    DDRB |= 1 << LED; // LED output
    DDRB &= ~(1 << BTN); // BTN input
    while (1) {
        if (PINB & (1 << BTN)) {
            PORTB &= ~(1 << LED);
        } else {
            PORTB |= 1 << LED;
        }
    }
}
