

typedef enum {

   PWM0, PWM1, PWM2, PWM3, PWM4, PWM5, PWM6, PWM7, PWM8, PWM9, PWM10

} pwmMap_t;





typedef const enum{

   PWM_ENABLE, PWM_DISABLE,

   PWM_ENABLE_OUTPUT, PWM_DISABLE_OUTPUT

} pwmInit_t;



_Bool 

      pwmInit( pwmMap_t pwmNumber, pwmInit_t config);













uint8_t pwmIsAttached( pwmMap_t pwmNumber );















uint8_t pwmRead( pwmMap_t pwmNumber );

















_Bool 

      pwmWrite( pwmMap_t pwmNumber, uint8_t percent );
