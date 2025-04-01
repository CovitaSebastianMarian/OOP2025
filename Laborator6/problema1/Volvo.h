#pragma once
#include "Car.h"
class Volvo : public Car {
public:
    Volvo();
    float GetSpeed(Weather weather) const override;
    float GetFuelConsumption() const override;
    float GetFuelCapacity() const override;
    const char* GetName() const override;
};

