#include "unity.h"
#include "leds.h"

uint16_t ledsVirtuales;

void setUp(void){
    Leds_Create(&ledsVirtuales);
}

void stearDown(void){
}

//apagar los leds despues de crear
void ledOffAfterCreate(void){
uint16_t ledsVirtuales= 0xFFFF;
TEST_ASSERT_EQUAL_HEX16(0,ledsVirtuales);
}

//se puede prender un led individual
void test_prender_led_individual(void){
Leds_On(1);
TEST_ASSERT_EQUAL_HEX16(1,ledsVirtuales);
}

//se puede apagar un led individual
void test_apagar_led_individual(void){ 
Leds_On(1);
Leds_Off(1);
TEST_ASSERT_EQUAL_HEX16(0,ledsVirtuales);
}

//se puede prender y apagar leds simultaneamente
void test_prender_apagar_led_simultaneo(void){
Leds_On(3);
Leds_On(4);
Leds_Off(3);
TEST_ASSERT_EQUAL_HEX16(1 <<3,ledsVirtuales);
}

//no se puede prender un led que no existe
void test_prender_led_que_no_existe(void){
Leds_On(18);
TEST_ASSERT_EQUAL_HEX16(0,ledsVirtuales);
}

//se pueden prender todos los leds a la vez
void test_prender_todos_los_leds(void){ 
Leds_All_On();
TEST_ASSERT_EQUAL_HEX16(0xFFFF,ledsVirtuales);
}

//se pueden apagar todos los leds a la vez
void test_apagar_todos_los_leds(void){ 
Leds_On(3);
Leds_On(4); //enciendo algunos leds
Leds_All_Off();
TEST_ASSERT_EQUAL_HEX16(0,ledsVirtuales);
}

//se pueden saber el estado de los leds 
void test_estado_de_los_leds_om(void){ 
Leds_On(5);
TEST_ASSERT_TRUE_MESSAGE(Leds_state(5), "està encendido ");
}

//se pueden saber el estado de los leds 
void test_estado_de_los_leds_off(void){ 
Leds_On(7);
Leds_Off(7);
TEST_ASSERT_FALSE_MESSAGE(Leds_state(7), "està encendido ");
}

//Revisar lìmites de los parametros  
void test_lim_parametros(void){ 
Leds_All_Off();
Leds_On(1);
Leds_On(16);
TEST_ASSERT_EQUAL_HEX16(0x8001,ledsVirtuales);
}

//Revisar parametros fuera de lìmites  
void test_param_fuera_limite(void){ 
Leds_All_Off();
Leds_On(0);
Leds_On(17);
TEST_ASSERT_EQUAL_HEX16(0,ledsVirtuales);
}
