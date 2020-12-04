/*=====[motorDrive]===========================================================
 * Author Sergio Alberino <alberino@gmail.com>
 * All rights reserved.
 * Version: 1.0.0
 * Creation Date: 2020/08/14
 */
 
/*=====[Inclusion of own header]=============================================*/
#include "sapi_gpio.h"
#include "sapi_pwm.h"
#include <motorDrive.h>

/*=====[Inclusions of private function dependencies]=========================*/

/*=====[Definition macros of private constants]==============================*/

/*=====[Private function-like macros]========================================*/

/*=====[Definitions of private data types]===================================*/

/*=====[Definitions of external public global variables]=====================*/

/*=====[Definitions of public global variables]==============================*/

bool_t valor = 0;
uint8_t  pwm1 = 200; /* 0 a 255 */
uint8_t  pwm2 = 0; /* 0 a 255 */

/*=====[Definitions of private global variables]=============================*/

/*=====[Prototypes (declarations) of private functions]======================*/

/*=====[Implementations of public functions]=================================*/

void motorDriveInit( void )
{
	 /* Configurar PWM */
	   valor = pwmConfig( 0, PWM_ENABLE );

	   valor = pwmConfig( PWM5, PWM_ENABLE_OUTPUT );
	   valor = pwmConfig( PWM6, PWM_ENABLE_OUTPUT );
}

void motorDriveUpdate(motors_t motorstate)
{

    switch( motorstate ){

    	case motorsFW:
		pwmWrite( PWM5, pwm1);
	    pwmWrite( PWM6, pwm1);
    		break;

    	case motorsTR:
	    pwmWrite( PWM5, pwm1);
	    pwmWrite( PWM6, pwm2);
    		break;

    	case motorsTL:
	    pwmWrite( PWM5, pwm2);
	    pwmWrite( PWM6, pwm1);
    		break;

    	case motorsST:
	    pwmWrite( PWM5, pwm2);
	    pwmWrite( PWM6, pwm2);
    		break;

    	default:
    		break;
    	}
}

/*=====[Implementations of interrupt functions]==============================*/

/*=====[Implementations of private functions]================================*/
