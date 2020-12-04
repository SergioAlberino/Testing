#ifndef mock_sapi_gpio_H
#define mock_sapi_gpio_H

#include "fff.h"
#include "fff_unity_helper.h"
#include "sapi_gpio.h"


DECLARE_FAKE_VALUE_FUNC2(_Bool, gpioInit, gpioMap_t, gpioInit_t);
DECLARE_FAKE_VALUE_FUNC1(_Bool, gpioRead, gpioMap_t);
DECLARE_FAKE_VALUE_FUNC2(_Bool, gpioWrite, gpioMap_t, _Bool);
DECLARE_FAKE_VALUE_FUNC1(_Bool, gpioToggle, gpioMap_t);

void mock_sapi_gpio_Init(void);
void mock_sapi_gpio_Verify(void);
void mock_sapi_gpio_Destroy(void);

#endif // mock_sapi_gpio_H
