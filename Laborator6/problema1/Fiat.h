#pragma once
#include "Car.h"
class Fiat : public Car {
public:
    Fiat();
    float GetSpeed(Weather weather) const override;
    float GetFuelConsumption() const override;
    float GetFuelCapacity() const override;
    const char* GetName() const override;
};

