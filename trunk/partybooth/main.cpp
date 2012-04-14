#include "common.h"
#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>

static const uint8_t LED = PB0;
static const uint8_t BTN = PB1;

ISR(TIM0_COMPA_vect) {
    static uint16_t counter = 0;

    OCR0A ^= 1;
    if (++counter >= 4000) {
        counter = 0;
        // every second, toggle LED
        PORTB ^= ~(1 << LED);
    }
}

int main() {
    TCCR0B = 2; // top = OCRA
    TCCR0B = 2; // clk/8 prescale
    OCR0A = 37;
    TCNT0 = 0;
    TIMSK0 = 4; // Enable interrupt for compare match A
    sei();
    while (true) {
        sleep_mode();
    }
}
