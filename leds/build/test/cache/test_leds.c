#include "build/temp/_test_leds.c"
#include "src/leds.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"


uint16_t ledsVirtuales;



void setUp(void){

    Leds_Create(&ledsVirtuales);

}



void stearDown(void){

}





void ledOffAfterCreate(void){

uint16_t ledsVirtuales= 0xFFFF;

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

((void *)0)

), (UNITY_UINT)(16), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_led_individual(void){

Leds_On(1);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

((void *)0)

), (UNITY_UINT)(22), UNITY_DISPLAY_STYLE_HEX16);

}





void test_apagar_led_individual(void){

Leds_On(1);

Leds_Off(1);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

((void *)0)

), (UNITY_UINT)(29), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_apagar_led_simultaneo(void){

Leds_On(3);

Leds_On(4);

Leds_Off(3);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 <<3)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

((void *)0)

), (UNITY_UINT)(37), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_led_que_no_existe(void){

Leds_On(18);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

((void *)0)

), (UNITY_UINT)(43), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_todos_los_leds(void){

Leds_All_On();

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

((void *)0)

), (UNITY_UINT)(49), UNITY_DISPLAY_STYLE_HEX16);

}





void test_apagar_todos_los_leds(void){

Leds_On(3);

Leds_On(4);

Leds_All_Off();

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

((void *)0)

), (UNITY_UINT)(57), UNITY_DISPLAY_STYLE_HEX16);

}





void test_estado_de_los_leds_om(void){

Leds_On(5);

do {if ((Leds_state(5))) {} else {UnityFail( ((("està encendido "))), (UNITY_UINT)((UNITY_UINT)(63)));}} while(0);

}





void test_estado_de_los_leds_off(void){

Leds_On(7);

Leds_Off(7);

do {if (!(Leds_state(7))) {} else {UnityFail( ((("està encendido "))), (UNITY_UINT)((UNITY_UINT)(70)));}} while(0);

}





void test_lim_parametros(void){

Leds_All_Off();

Leds_On(1);

Leds_On(16);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x8001)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

((void *)0)

), (UNITY_UINT)(78), UNITY_DISPLAY_STYLE_HEX16);

}





void test_param_fuera_limite(void){

Leds_All_Off();

Leds_On(0);

Leds_On(17);

UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

((void *)0)

), (UNITY_UINT)(86), UNITY_DISPLAY_STYLE_HEX16);

}
