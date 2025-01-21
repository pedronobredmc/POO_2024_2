#include <iostream>
#include <string>

class Pet{
    private:
        int energyMax;
        int hungryMax;
        int cleanMax;
        int energy;
        int hungry;
        int clean;
        int diamonds;
        int age;
        bool alive;
    public:
        Pet(int energy=0, int hungry=0, int clean=0) {
            this->energyMax = energy;
            this->hungryMax = hungry;
            this->cleanMax = clean;
            this->energy = energy;
            this->hungry = hungry;
            this->clean = clean;
            this->diamonds = 0;
            this->age = 0;
            this->alive = true;
        }
        bool isAlive() {
            return this->alive;
        }
        /*std::string toStr(){

        }*/
        void setEnergy(int value) {
            this->energy = value;
        }
        void setHungry(int value) {
            this->hungry = value;
        }
        void setClean(int value) {
            this->clean = value;
        }
        void setDiamonds(int value) {
            this->diamonds = value;
        }
        void setAge(int value) {
            this->age = value;
        }
        void setAlive(bool value) {
            this->alive = value;
        }
        int getClean(){
            return this->clean;
        }
        int getHungry(){
            return this->hungry;
        }
        int getEnergy(){
            return this->energy;
        }
        int getCleanMax(){
            return this->cleanMax;
        }
        int getHungryMax(){
            return this->hungryMax;
        }
        int getEnergyMax(){
            return this->energyMax;
        }
        int getDiamonds(){
            return this->diamonds;
        }
        int getAge(){
            return this->age;
        }
};

class Game {
    private:
        Pet pet;
        void testAlive(){
            if(this->pet.getEnergy() <= 0){
                this->pet.setEnergy(0);
                this->pet.setAlive(false);
            }else if(this->pet.getHungry() <= 0){
                this->pet.setHungry(0);
                this->pet.setAlive(false);
            }else if(this->pet.getClean() <= 0){
                this->pet.setClean(0);
                this->pet.setAlive(false);
            }else{
                this->pet.setAlive(true);
            }
        }
    public:
    Game(Pet pet=Pet()){
        this->pet = pet;
    }
    std::string str(){
        return "E:" + std::to_string(this->pet.getEnergy()) + "/" + std::to_string(this->pet.getEnergyMax()) + ", S:" + std::to_string(this->pet.getHungry()) + "/" + std::to_string(this->pet.getHungryMax()) + ", L:" + std::to_string(this->pet.getClean()) + "/" + std::to_string(this->pet.getCleanMax()) + ", D:" + std::to_string(this->pet.getDiamonds()) + ", I:" + std::to_string(this->pet.getAge());
    }
    void play(){
        testAlive();
        if(this->pet.isAlive() == true){
            if(this->pet.getClean() - 3 <= 0){
                std::cout << "fail: pet morreu de sujeira" << std::endl;
                this->pet.setClean(this->pet.getClean() - 3);
                this->pet.setEnergy(this->pet.getEnergy() - 2);
                this->pet.setHungry(this->pet.getHungry() - 1);
                this->pet.setAge(this->pet.getAge() + 1);
                this->pet.setDiamonds(this->pet.getDiamonds() + 1);
            }else if(this->pet.getEnergy() - 2 <= 0){
                std::cout << "fail: pet morreu de fraqueza" << std::endl;
                this->pet.setClean(this->pet.getClean() - 3);
                this->pet.setEnergy(this->pet.getEnergy() - 2);
                this->pet.setHungry(this->pet.getHungry() - 1);
                this->pet.setAge(this->pet.getAge() + 1);
                this->pet.setDiamonds(this->pet.getDiamonds() + 1);
            }else if(this->pet.getHungry() - 1 <= 0){
                std::cout << "fail: pet morreu de fome" << std::endl;
                this->pet.setClean(this->pet.getClean() - 3);
                this->pet.setEnergy(this->pet.getEnergy() - 2);
                this->pet.setHungry(this->pet.getHungry() - 1);
                this->pet.setAge(this->pet.getAge() + 1);
                this->pet.setDiamonds(this->pet.getDiamonds() + 1);
            }else{
                this->pet.setClean(this->pet.getClean() - 3);
                this->pet.setEnergy(this->pet.getEnergy() - 2);
                this->pet.setHungry(this->pet.getHungry() - 1);
                this->pet.setAge(this->pet.getAge() + 1);
                this->pet.setDiamonds(this->pet.getDiamonds() + 1);
            }
        }else{
            std::cout << "fail: pet esta morto" << std::endl;
        }
    }
    void shower(){
        testAlive();
        if(this->pet.isAlive() == true){
            this->pet.setClean(this->pet.getCleanMax());
            this->pet.setEnergy(this->pet.getEnergy() - 3);
            this->pet.setAge(this->pet.getAge() + 2);
            this->pet.setHungry(this->pet.getHungry() - 1);
        }else{
            std::cout << "fail: pet esta morto" << std::endl;
        }
    }
    void eat(){
        testAlive();
        if(this->pet.isAlive() == true){
            this->pet.setEnergy(this->pet.getEnergy() - 1);
            if(this->pet.getHungry() + 4 >= this->pet.getHungryMax()){
                this->pet.setHungry(this->pet.getHungryMax());
            }else{
                this->pet.setHungry(this->pet.getHungry() + 4);
            }
            this->pet.setAge(this->pet.getAge() + 1);
            this->pet.setClean(this->pet.getClean() - 2);
        }else{
            std::cout << "fail: pet esta morto" << std::endl;
        }
    }
    void sleep(){
        testAlive();
        if(this->pet.isAlive() == true){
            if(this->pet.getEnergyMax() - this->pet.getEnergy() >= 5){
                for(int i = this->pet.getEnergy(); i < this->pet.getEnergyMax(); i++){
                    this->pet.setEnergy(this->pet.getEnergy() + 1);
                    this->pet.setAge(this->pet.getAge() + 1);
                }

                this->pet.setHungry(this->pet.getHungry() - 1);
            }else{
                std::cout << "fail: nao esta com sono" << std::endl;
            }
        }else{
            std::cout << "fail: pet esta morto" << std::endl;
        }
    }
};



class Student {
private:
    Game game;
public:
    Student(int energy, int hungry, int clean) {
        (void) energy;
        (void) hungry;
        (void) clean;
        this->game = Game(Pet(energy, hungry, clean));
    }

    void show() {
        std::cout << this->game.str() << std::endl;
    }

    void play() {
        this->game.play();
    }

    void shower() {
        this->game.shower();
    }

    void eat() {
        this->game.eat();
    }

    void sleep() {
        this->game.sleep();
    }
};