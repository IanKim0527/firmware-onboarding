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
    float interval = 1000 - (temperature * 20);

    if (interval < 100)
    {
        interval = 100;
    }
    return interval;
}
