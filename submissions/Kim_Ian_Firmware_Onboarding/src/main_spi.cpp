#include <Arduino.h>
#include "BMESPIInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

void setup()
{
    pinMode(BMEConstants::LED_PIN, OUTPUT);
    BMESPIInterfaceInstance::instance().initialize();
}
void loop()
{
    float temperature = BMESPIInterfaceInstance::instance().getTemperature();
    LEDControllerInstance::instance().update(temperature);
}
