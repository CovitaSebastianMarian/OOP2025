#include "Volvo.h"

Volvo::Volvo()
{
    fuelCapacity = 60;
    fuelConsumption = 8;
    averageSpeed[0] = 120;
    averageSpeed[1] = 90;
    averageSpeed[2] = 60;
}

float Volvo::GetSpeed(Weather weather) const
{
    return averageSpeed[static_cast<int>(weather)];
}

float Volvo::GetFuelConsumption() const
{
    return fuelConsumption;
}

float Volvo::GetFuelCapacity() const
{
    return fuelCapacity;
}

const char* Volvo::GetName() const
{
    return "Volvo";
}
