
#include "leds.h"
#define  LEDS_ALL_OFF   0x0000
#define LED_OFFSET      1
#define LSB             1
#define LedsToMask(led)   (LSB<< (led-LED_OFFSET))

static uint16_t *direccion;


//es un cosntructor que prepara
void Leds_Create(uint16_t *puerto) {
    direccion = puerto;
    *puerto = LEDS_ALL_OFF;
}

void Leds_On(uint8_t led) {
   *direccion |= LedsToMask(led);
}
void Leds_Off(uint8_t led) {
    *direccion &= ~LedsToMask(led);
}

void Leds_All_On(void) {
    *direccion = ~LEDS_ALL_OFF;
}
void Leds_All_Off(void) {
    *direccion = LEDS_ALL_OFF;
}
uint16_t Leds_state(void) {
    return *direccion;
}


