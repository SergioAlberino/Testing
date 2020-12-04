/*=====[motorDrive]===========================================================
 * Author Sergio Alberino <alberino@gmail.com>
 * All rights reserved.
 * Version: 1.0.0
 * Creation Date: 2020/08/14
 */

/*=====[Avoid multiple inclusion - begin]====================================*/

#ifndef _MOTORDRIVE_H_
#define _MOTORDRIVE_H_

/*=====[Inclusions of public function dependencies]==========================*/
#include "sapi_gpio.h"
#include "sapi_pwm.h"

/*=====[C++ - begin]=========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Definition macros of public constants]===============================*/

/*=====[Public function-like macros]=========================================*/

/*=====[Definitions of public data types]====================================*/
typedef enum{
    motorsFW,
    motorsTR,
    motorsTL,
    motorsST,
} motors_t;

/*=====[Prototypes (declarations) of public functions]=======================*/

void motorDriveInit( void );
void motorDriveUpdate(motors_t motorstate);

/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* _MOTORDRIVE_H_ */

