#include "BMW.h"

BMW::BMW()
{
    fuelCapacity = 55;
    fuelConsumption = 9;
    averageSpeed[0] = 140;
    averageSpeed[1] = 100;
    averageSpeed[2] = 70;
}

float BMW::GetSpeed(Weather weather) const
{
    return averageSpeed[static_cast<int>(weather)];
}

float BMW::GetFuelConsumption() const
{
    return fuelConsumption;
}

float BMW::GetFuelCapacity() const
{
    return fuelCapacity;
}

const char* BMW::GetName() const
{
    return "BMW";
}