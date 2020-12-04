/*=====[Statemachine]===========================================================
 * Author Sergio Alberino <alberino@gmail.com>
 * Test de parte del còdigo del proyecto Robot para limpieza y desinfecciòn
 * Version: 1.0
 * Creation Date: 2020/11/30
 */
 
//******* includes ********
#include "unity.h"
#include <statemachine.h>
#include "mock_sapi_gpio.h"
#include <sensors.h>
#include <motorDrive.h>
#include "mock_sapi_pwm.h"

//*******  Variables locales ********
uint8_t state;
//gpioMap_t sensoresVirtuales[]={sensorF,sensorR,button};
bool_t ret;
bool_t valSensorF;
bool_t valSensorR;
bool_t valPushButton;

// States
typedef enum{ 
    FORWARD,
    TURN_R,
    TURN_L,
	STOPPED,
} state_t;


//******** Ceedling Tests / setUp *********
void setUp(void){
	valPushButton=false;	
	valSensorF=false;
	valSensorR=false;
	statemachineInit(); // condicion inical

}
//******** Ceedling Tests / stearDown *********
void stearDown(void){
}


// ******** Ceedling Tests / Lista de tests ************
// Test de la inicialización
// TTest inicio en estado STOPPED
// Test de paso a estado FORWARD
// Test secuencia de estados GIRO TURN_R, obstaculo al frente
// Test secuencia de estados GIRO TURN_L, obstaculo al frente y lateral
// Test se detiene despues de haber arrancado


// Test de la inicialización
void test_state_machine_init(void){
	//ret= statemachineInit();  // no hace falta porque inicializa como condicion inicail del test
	TEST_ASSERT_TRUE_MESSAGE(statemachineInit(), "Se inicializò correctamente ");
}

// TTest inicio en estado STOPPED
void test_state_initial(void){
	//statemachineInit(); // no hace falta porque inicializa como condicion inicail del test
	TEST_ASSERT_EQUAL_MESSAGE(3, statemachineUpdate(), "Se inicializo en STOPPED ");
}

// Test de paso a estado FORWARD
void test_state_go_forward(void){
	valPushButton=true;	// se presiona pushButton
	statemachineUpdate();	// pasa a FORWARD
	TEST_ASSERT_EQUAL_MESSAGE(0, statemachineUpdate(), "paso a FORWARD ");
}

// Test secuencia de estados GIRO TURN_R, obstaculo al frente
void test_state_go_turn_right(void){

	valPushButton=true;	// se presiona pushButton
	statemachineUpdate();	// pasa a FORWARD
	valPushButton=false;	// se libera pushButton	
	statemachineUpdate();
	valSensorF=true;	// sensor de frente detecta obstaculo
	valSensorR=false;	// sensor lateral no detecta
	statemachineUpdate();
	TEST_ASSERT_EQUAL_MESSAGE(1, statemachineUpdate(), "TURN_R ");
}


// Test secuencia de estados GIRO TURN_L, obstaculo al frente y lateral
void test_state_go_turn_left(void){
	valPushButton=true;	// se presiona pushButton
	statemachineUpdate();	// pasa a FORWARD
	valPushButton=false;	// se libera pushButton
	statemachineUpdate();
	valSensorF=true;	// sensor de frente detecta obstaculo
	valSensorR=true;	// sensor lateral activado
	statemachineUpdate();
	TEST_ASSERT_EQUAL_MESSAGE(2, statemachineUpdate(), "TURN_L ");
}

// Test se detiene despues de haber arrancado
void test_state_go_stopped_again(void){

	valPushButton=true;	// se presiona pushButton
	statemachineUpdate();	// pasa a FORWARD
	valPushButton=false;	// se libera pushButton
	statemachineUpdate();
	valPushButton=true;	// se presiona pushButton
	statemachineUpdate();	// pasa a STOPPED
	TEST_ASSERT_EQUAL_MESSAGE(3, statemachineUpdate(), "paso a FORWARD - STOPPED ");
}


//apagar los leds despues de crear
//void ledOffAfterCreate(void){
//uint16_t ledsVirtuales= 0xFFFF;
//TEST_ASSERT_EQUAL_HEX16(0,ledsVirtuales);


