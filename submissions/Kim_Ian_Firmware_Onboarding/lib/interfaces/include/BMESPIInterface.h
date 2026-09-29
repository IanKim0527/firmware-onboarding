#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMESPIInterface
{
public:
    BMESPIInterface();
    bool initialize();
    float getTemperature();

private:
    Adafruit_BME280 bme;
};
using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;