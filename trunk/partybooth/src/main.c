#define F_CPU 1200000UL
#include <avr/io.h>

#define LED PB0
#define BTN PB1

int main(void) {
    DDRB |= 1 << LED; // LED output
    DDRB &= ~(1 << BTN); // BTN input
    while (1) {
        if (PINB & (1 << BTN)) {
            PORTB &= ~(1 << LED);
        } else {
            PORTB |= 1 << LED;
        }
    }
    return 0;
}
