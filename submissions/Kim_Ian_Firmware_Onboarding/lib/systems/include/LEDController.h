#pragma once
#include <Arduino.h>
#include "BMEConstants.h"
#include <etl/singleton.h>

class LEDController
{
public:
    LEDController() = default;
    void update(float temperature);

private:
    float calculateBlinkInterval(float temperature);
    bool ledState = false;
    unsigned long previousMillis = 0;
    float blinkInterval = 1000;
};
using LEDControllerInstance = etl::singleton<LEDController>;