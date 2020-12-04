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



_Bool 

      valSensorF;



_Bool 

      valSensorR;



_Bool 

      valPushButton;





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



 do {if ((statemachineInit())) {} else {UnityFail( ((("Se inicializò correctamente "))), (UNITY_UINT)((UNITY_UINT)(58)));}} while(0);

}





void test_state_initial(void){



 UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((statemachineUpdate())), (("Se inicializo en STOPPED ")), (UNITY_UINT)(64), UNITY_DISPLAY_STYLE_INT);

}





void test_state_go_forward(void){

 valPushButton=

              1

                  ;

 statemachineUpdate();

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((statemachineUpdate())), (("paso a FORWARD ")), (UNITY_UINT)(71), UNITY_DISPLAY_STYLE_INT);

}





void test_state_go_turn_right(void){



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

 statemachineUpdate();

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((statemachineUpdate())), (("TURN_R ")), (UNITY_UINT)(84), UNITY_DISPLAY_STYLE_INT);

}







void test_state_go_turn_left(void){

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

 statemachineUpdate();

 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((statemachineUpdate())), (("TURN_L ")), (UNITY_UINT)(97), UNITY_DISPLAY_STYLE_INT);

}





void test_state_go_stopped_again(void){



 valPushButton=

              1

                  ;

 statemachineUpdate();

 valPushButton=

              0

                   ;

 statemachineUpdate();

 valPushButton=

              1

                  ;

 statemachineUpdate();

 UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((statemachineUpdate())), (("paso a FORWARD - STOPPED ")), (UNITY_UINT)(109), UNITY_DISPLAY_STYLE_INT);

}
