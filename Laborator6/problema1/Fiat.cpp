#include "Fiat.h"


Fiat::Fiat()
{
    fuelCapacity = 45;
    fuelConsumption = 6.5;
    averageSpeed[0] = 110;
    averageSpeed[1] = 85;
    averageSpeed[2] = 55;
}

float Fiat::GetSpeed(Weather weather) const
{
    return averageSpeed[static_cast<int>(weather)];
}

float Fiat::GetFuelConsumption() const
{
    return fuelConsumption;
}

float Fiat::GetFuelCapacity() const
{
    return fuelCapacity;
}

const char* Fiat::GetName() const
{
    return "Fiat";
}