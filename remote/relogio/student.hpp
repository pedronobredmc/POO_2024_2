#pragma once
#include "fn.hpp"

class Student {
private:
    int HOUR {0};
    int MINUTE {0};
    int SECOND {0};
public:
    Student(int hour = 0, int minute = 0, int second = 0) {
        // this->time = Time(hour, minute, second);
        if(hour < 0 || hour > 23){
            std::cout << "fail: hora invalida\n";
        }else{
            this->HOUR = hour;
        }
        if(minute < 0 || minute > 59){
            std::cout << "fail: minuto invalido\n";
        }else{
            this->MINUTE = minute;
        }
        if(second < 0 || second > 59){
            std::cout << "fail: segundo invalido\n";
        }else{
            this->SECOND = second;
        }

    }

    void setHour(int hour) {
        (void) hour;
        // this->time.setHour(hour);
        if(hour < 0 || hour > 23) {
            std::cout << "fail: hora invalida\n";
        }else{
            this->HOUR = hour;
        }
    }

    void setMinute(int minute) {
        (void) minute;
        // this->time.setMinute(minute);
        if(minute < 0 || minute > 59) {
            std::cout << "fail: minuto invalido\n";
        }else{
            this->MINUTE = minute;
        }
    }
    void setSecond(int second) {
        (void) second;
        // this->time.setSecond(second);
        if(second < 0 || second > 59) {
            std::cout << "fail: segundo invalido\n";
        }else{
            this->SECOND = second;
        }
    }

    void nextSecond() {
        // this->time.nextSecond();
        this->SECOND++;
        if(this->SECOND == 60) {
            this->SECOND = 0;
            this->MINUTE++;
            if(this->MINUTE == 60) {
                this->MINUTE = 0;
                this->HOUR++;
                if(this->HOUR == 24) {
                    this->HOUR = 0;
                }
            }
        }
    }
    
    void show() {
        // fn::write(time);
        std::cout << std::setfill('0') << std::setw(2) << this->HOUR << ":" << std::setw(2) << this->MINUTE << ":" << std::setw(2) << this->SECOND << std::endl;
    }
};