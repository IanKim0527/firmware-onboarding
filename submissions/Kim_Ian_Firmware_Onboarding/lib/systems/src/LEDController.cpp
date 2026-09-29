#include "LEDController.h"

void LEDController::update(float temperature)
{
    float blinkInterval = calculateBlinkInterval(temperature);
    delay(blinkInterval);
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= blinkInterval)
    {
        previousMillis = currentMillis;
        ledState = !ledState;
        digitalWrite(BMEConstants::LED_PIN, ledState);
    }
}
float LEDController::calculateBlinkInterval(float temperature)
{
    if (temperature < 10.0)
    {
        return 1000;
    }
    else if (temperature < 25)
    {
        return 600;
    }
    else if (temperature < 35)
    {
        return 300;
    }
    else
    {
        return 100;
    }
}
