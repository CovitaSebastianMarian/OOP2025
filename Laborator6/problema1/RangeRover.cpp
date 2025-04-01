#include "RangeRover.h"

RangeRover::RangeRover()
{
    fuelCapacity = 70;
    fuelConsumption = 12;
    averageSpeed[0] = 125;
    averageSpeed[1] = 85;
    averageSpeed[2] = 50;
}

float RangeRover::GetSpeed(Weather weather) const
{
    return averageSpeed[static_cast<int>(weather)];
}

float RangeRover::GetFuelConsumption() const
{
    return fuelConsumption;
}

float RangeRover::GetFuelCapacity() const
{
    return fuelCapacity;
}

const char* RangeRover::GetName() const
{
    return "Range Rover";
}