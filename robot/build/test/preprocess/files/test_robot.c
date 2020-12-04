#include "build/temp/_test_robot.c"
#include "build/test/mocks/mock_sapi_pwm.h"
#include "inc/motorDrive.h"
#include "inc/sensors.h"
#include "build/test/mocks/mock_sapi_gpio.h"
#include "inc/statemachine.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"




uint8_t state;





_Bool 

      ret;





typedef enum{

    FORWARD,

    TURN_R,

    TURN_L,

 STOPPED,

} state_t;







void setUp(void){

 valPushButton=

              0

                   ;

 valSensorF=

           0

                ;

 valSensorR=

           0

                ;

 statemachineInit();



}



void stearDown(void){

}

void test_state_machine_init(void){



 do {if ((statemachineInit())) {} else {UnityFail( ((("Se inicializò correctamente "))), (UNITY_UINT)((UNITY_UINT)(54)));}} while(0);

}





void test_state_initial(void){



 UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((statemachineUpdate())), (("Se inicializo en STOPPED ")), (UNITY_UINT)(60), UNITY_DISPLAY_STYLE_INT);

}





void test_state_go_forward(void){

 statemachineInit();

 valPushButton=

              1

                  ;

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((statemachineUpdate())), (("paso a FORWARD ")), (UNITY_UINT)(67), UNITY_DISPLAY_STYLE_INT);

}





void test_state_go_turn(void){

 statemachineInit();

 valPushButton=

              1

                  ;

 statemachineUpdate();

 valPushButton=

              0

                   ;

 statemachineUpdate();

 valSensorF=

           1

               ;

 valSensorR=

           0

                ;

 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((statemachineUpdate())), (("paso a GIRO ")), (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_INT);

}



void test_state_go_forward_again(void){

 valSensorF=

           0

                ;

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((statemachineUpdate())), (("vuelve a ir para FORWARD ")), (UNITY_UINT)(84), UNITY_DISPLAY_STYLE_INT);

}





void test_state_go_turn_othes_side(void){

 statemachineInit();

 valPushButton=

              1

                  ;

 statemachineUpdate();

 valPushButton=

              0

                   ;

 statemachineUpdate();

 valSensorF=

           1

               ;

 valSensorR=

           1

               ;

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((statemachineUpdate())), (("vuelve a ir para FORWARD ")), (UNITY_UINT)(96), UNITY_DISPLAY_STYLE_INT);

}
