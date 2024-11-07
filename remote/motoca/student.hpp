#pragma once
#include <iostream>

class Person{
    private:
    int age=0;
    std::string name;
    public:
    Person(std::string name="", int age=0){
        this->name = name;
        this->age = age;
    }
    int getAge() {
        return age;
    }
    std::string getName() {
        return name;
    }
    std::string str(){
        if(this->name == ""){
            return "empty";

        }else{
            return name + ":" + std::to_string(age);
        }
    }

};


class Motorcycle{
    private:
    Person pessoa;
    int power=1;
    int time=0;
    public:
    Motorcycle(int power=1){
        this->power = power;
        this->time = 0;
    }
    bool insertPerson(Person pessoa){
        if(this->pessoa.getName() == "" || this->pessoa.getName() == "empty"){
            this->pessoa = pessoa;
            return true;
        }
        else{
            std::cout << "fail: busy motorcycle" << std::endl;
            return false;
        }
    }
    Person remove(){
        if(this->pessoa.getName() == "" || pessoa.getName() == "empty"){
            std::cout << "fail: empty motorcycle" << std::endl;
            return Person();
        }
        else{
            Person aux = this->pessoa;
            this->pessoa = Person();
            return aux;
        }
    }
    void buyTime(int time){
        this->time = this->time+time;
    }
    void drive(int time){
        if(this->time == 0){
            std::cout << "fail: buy time first" << std::endl;
        }else if(this->pessoa.getName() == ""){
            std::cout << "fail: empty motorcycle" << std::endl;
        }else if(this->pessoa.getAge() > 10){
            std::cout << "fail: too old to drive" << std::endl;
        }else if(this->time < time){
            std::cout << "fail: time finished after "<< time - this->time  << " minutes" << std::endl;
            this->time = 0;
        }else{
            this->time -= time;
        }
    }
    std::string honk(){
        std::string result = "P";
        for(int i = 0; i < power; i++){
            result += "e";
        }
        result += "m";
        return result;
    }
    Person getPerson(){
        return pessoa;
    }
    int getPower(){
        return power;
    }
    int getTime(){
        return time;
    }
    std::string str(){
        return + "power:" + std::to_string(this->power) + ", time:" + std::to_string(time) + ", person:(" + pessoa.str() + ")";
    }
};

class Student {
    Motorcycle motorcycle;
public:

    Student(int power = 1){
        //(void) power;
        motorcycle = Motorcycle(power);
    }

    void enter(std::string name, int age){
        Person person = Person(name, age);
        motorcycle.insertPerson(person);
        //(void) name;
        //(void) age;
    }

    void leave(){
        Person person = motorcycle.remove();
        fn::write(person.str() == "empty" ? "---" : person.str());
    }

    void honk(){
        fn::write(motorcycle.honk());
    }

    void buy(int time) {
        motorcycle.buyTime(time);
    }

    void drive(int time) {
        motorcycle.drive(time);
        (void) time;
    }

    void show(){
        fn::write(motorcycle.str());
    }
};