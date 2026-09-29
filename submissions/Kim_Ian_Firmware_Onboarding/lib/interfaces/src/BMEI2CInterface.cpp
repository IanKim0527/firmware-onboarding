#include "BMEI2CInterface.h"

bool BMEI2CInterface::initialize()
{
    return bme.begin(BMEConstants::BME_I2C_ADDRESS);
}
float BMEI2CInterface::getTemperature()
{
    return bme.readTemperature();
}
