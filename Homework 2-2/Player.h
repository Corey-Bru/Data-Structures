#pragma once
#include <iostream>
#include "Wheel.h"
class Player : public Wheel
{
private:
	double money = 1000;
public:
//Setters:
    void setMoney(double m) {
        money = m;
    }

//Getters:
    double getMoney() {
        return money;
    }
};

