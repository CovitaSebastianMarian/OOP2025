#pragma once
#include "Car.h"
class BMW : public Car {
public:
    BMW();
    float GetSpeed(Weather weather) const override;
    float GetFuelConsumption() const override;
    float GetFuelCapacity() const override;
    const char* GetName() const override;
};

