#include <string.h>
#include "fff.h"
#include "mock_sapi_pwm.h"

DEFINE_FAKE_VALUE_FUNC2(_Bool, pwmInit, pwmMap_t, pwmInit_t);
DEFINE_FAKE_VALUE_FUNC1(uint8_t, pwmIsAttached, pwmMap_t);
DEFINE_FAKE_VALUE_FUNC1(uint8_t, pwmRead, pwmMap_t);
DEFINE_FAKE_VALUE_FUNC2(_Bool, pwmWrite, pwmMap_t, uint8_t);

void mock_sapi_pwm_Init(void)
{
    FFF_RESET_HISTORY();
    RESET_FAKE(pwmInit)
    RESET_FAKE(pwmIsAttached)
    RESET_FAKE(pwmRead)
    RESET_FAKE(pwmWrite)
}
void mock_sapi_pwm_Verify(void)
{
}
void mock_sapi_pwm_Destroy(void)
{
}
