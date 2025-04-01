#pragma once
#include "Car.h"
class RangeRover : public Car {
public:
    RangeRover();
    float GetSpeed(Weather weather) const override;
    float GetFuelConsumption() const override;
    float GetFuelCapacity() const override;
    const char* GetName() const override;
};

