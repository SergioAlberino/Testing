#include <string.h>
#include "fff.h"
#include "mock_sapi_gpio.h"

DEFINE_FAKE_VALUE_FUNC2(_Bool, gpioInit, gpioMap_t, gpioInit_t);
DEFINE_FAKE_VALUE_FUNC1(_Bool, gpioRead, gpioMap_t);
DEFINE_FAKE_VALUE_FUNC2(_Bool, gpioWrite, gpioMap_t, _Bool);
DEFINE_FAKE_VALUE_FUNC1(_Bool, gpioToggle, gpioMap_t);

void mock_sapi_gpio_Init(void)
{
    FFF_RESET_HISTORY();
    RESET_FAKE(gpioInit)
    RESET_FAKE(gpioRead)
    RESET_FAKE(gpioWrite)
    RESET_FAKE(gpioToggle)
}
void mock_sapi_gpio_Verify(void)
{
}
void mock_sapi_gpio_Destroy(void)
{
}
