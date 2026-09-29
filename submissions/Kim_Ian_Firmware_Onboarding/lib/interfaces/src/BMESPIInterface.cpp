#include "BMESPIInterface.h"

BMESPIInterface::BMESPIInterface()
    : bme(BMEConstants::BME_CS_PIN)
{
}
bool BMESPIInterface::initialize()
{
    return bme.begin();
}
float BMESPIInterface::getTemperature()
{
    return bme.readTemperature();
}
