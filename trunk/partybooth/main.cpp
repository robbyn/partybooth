#include <avr/io.h>
#include <avr/sleep.h>

static const uint8_t LED = PB0;
static const uint8_t BTN = PB1;

int main() {
    set_sleep_mode(SLEEP_MODE_IDLE);   // set sleep mode 
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
