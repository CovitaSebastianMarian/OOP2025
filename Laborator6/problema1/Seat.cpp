#include "Seat.h"

Seat::Seat()
{
    fuelCapacity = 50;
    fuelConsumption = 7;
    averageSpeed[0] = 130;
    averageSpeed[1] = 95;
    averageSpeed[2] = 65;
}

float Seat::GetSpeed(Weather weather) const
{
    return averageSpeed[static_cast<int>(weather)];
}

float Seat::GetFuelConsumption() const
{
    return fuelConsumption;
}

float Seat::GetFuelCapacity() const
{
    return fuelCapacity;
}

const char* Seat::GetName() const
{
    return "Seat";
}