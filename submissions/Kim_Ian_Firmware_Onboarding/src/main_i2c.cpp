#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

void setup()
{
    pinMode(BMEConstants::LED_PIN, OUTPUT);
    BMEI2CInterfaceInstance::instance().initialize();
}
void loop()
{
    float temperature = BMEI2CInterfaceInstance::instance().getTemperature();
    LEDControllerInstance::instance().update(temperature);
}
