#ifndef mock_sapi_pwm_H
#define mock_sapi_pwm_H

#include "fff.h"
#include "fff_unity_helper.h"
#include "sapi_pwm.h"


DECLARE_FAKE_VALUE_FUNC2(_Bool, pwmInit, pwmMap_t, pwmInit_t);
DECLARE_FAKE_VALUE_FUNC1(uint8_t, pwmIsAttached, pwmMap_t);
DECLARE_FAKE_VALUE_FUNC1(uint8_t, pwmRead, pwmMap_t);
DECLARE_FAKE_VALUE_FUNC2(_Bool, pwmWrite, pwmMap_t, uint8_t);

void mock_sapi_pwm_Init(void);
void mock_sapi_pwm_Verify(void);
void mock_sapi_pwm_Destroy(void);

#endif // mock_sapi_pwm_H
