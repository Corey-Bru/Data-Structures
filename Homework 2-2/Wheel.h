#pragma once
#include <iostream>
#include <string>
#include <random>
using namespace std;
class Wheel {
private:
    int minNum = 1;
    int maxNum = 10;
public:

    Wheel() {
        minNum = 1;
        maxNum = 10;
    }
    Wheel(int max) {
        minNum = 1;
        maxNum = max;
    }
//Setters:
    void setMaxNum(int Max) {
        maxNum = Max;
    }
    void setMinNum(int Min) {
        minNum = Min;
    }

//Getters:
    int getMaxNum() {
        return maxNum;
    }

    int getMinNum() {
        return minNum;
    }

//Spin member function:
    int spin() {
       int number = rand() % (maxNum - minNum +1) + minNum;
       return number;
    }
    
};
