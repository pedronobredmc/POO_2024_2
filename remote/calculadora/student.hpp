#pragma once
#include "fn.hpp"

class Calculadora{
    // Calculator c;
    int batteryMax=0;
    int battery=0;
    float display=0.00;
public:
    void calculadora(int batteryMax) {
        // c = Calculator(0);
        this->battery = 0;
        this->batteryMax = batteryMax;
    }
    void show() {
        std::cout<<std::fixed;
        std::cout<<std::setprecision(2);
        std::cout << "display = "<< this->display << ", battery = " <<this->battery<< std::endl;
    }
    /*void init(int batteryMax) {
        // c = Calculator(batteryMax);
        (void) batteryMax;
    }*/
    void charge(int value) {
        // c.chargeBattery(value);
        if(this->battery + value > this->batteryMax) {
            this->battery = this->batteryMax;
        } else {
            this->battery += value;
        }
    }
    void sum(int a, int b) {
        // c.sum(a, b);
        // // ACT!
        // // (void) a;
        // // (void) b;
        if(this->battery <= 0) {
            std::cout << "fail: bateria insuficiente" << std::endl;
        }else{
            this->display = (a + b);
            this->battery--;
        }
    }
    void div(float num, float den) {
        // c.division(num, den);
        // // ACT!
        // // (void) num;
        // // (void) den;
        if(den != 0){
            if(this->battery <= 0) {
                std::cout << "fail: bateria insuficiente" << std::endl;
            }else{
                this->display = (num / den);
                this->battery--;
            }
        }else{
            std::cout << "fail: divisao por zero" << std::endl;
            this->battery--;
        }
        
    }
};
