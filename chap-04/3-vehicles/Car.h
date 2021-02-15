#pragma once

#include "Vehicle.h"

#include <iostream>

class Car : public Vehicle
{
public:
    Car(const Driver& driver, unsigned int speed)
        : Vehicle { driver }
        , _speed { speed }
    {}

    unsigned int drive() const override
    {
        if(_driver.has_car_licence())
        {
            std::cout << "Vrooooom!" << std::endl;
            return _speed;
        }
        std::cerr << "I can't launch the car!" << std::endl;
        return 0;
    }

protected:
    unsigned int _speed = 0;
};

class FlyingCar : public Car
{
private:
    const int _boost = 10;
public:
    FlyingCar(const Driver& driver, unsigned int speed) 
        : Car(driver, speed)
        {}
    
    unsigned int drive() const override
    {
        if(_driver.has_air_licence())
        {
            std::cout << "Flyyyyyyy!" << std::endl;
            return _boost *_speed; 
        }
        return Car::drive();
        
    }

};