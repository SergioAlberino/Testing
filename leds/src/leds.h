#include "stdint.h"
#include "stdbool.h"


void Leds_Create(uint16_t *puerto);
void Leds_On(uint8_t led); 
void Leds_Off(uint8_t led); 
void Leds_All_On(void);
void Leds_All_Off(void);
bool Leds_state(uint8_t led);
bool check_Leds(uint8_t led);
