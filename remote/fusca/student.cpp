#include "fn.hpp"
class Carro {
    public:
        int Fuel=0;
        int pass=0;
        int km=0;
        int max_fuel=100;
        int max_pass=2;
        // Car car;
        Carro() {
            this->Fuel = 0;
            this->pass = 0;
            this->km = 0;
        }
        void enter() {
            // car.enter();
            if (this->pass < this->max_pass) {
                this->pass++;
            }else if(this->pass >= this->max_pass){
                std::cout << "fail: limite de pessoas atingido" << std::endl;
            }
        }
        void leave() {
            // car.leave();
            if (this->pass > 0) {
                this->pass--;
            }else if(this->pass <= 0){
                std::cout << "fail: nao ha ninguem no carro" << std::endl;
            }
        }
        void fuel(int q) {
            // car.fuel(q);
            
            if(this->Fuel+q <= this->max_fuel){
                this->Fuel+=q;

            }else if(this->Fuel+q > this->max_fuel){
                this->Fuel = this->max_fuel;
            }    
        }
        void drive(int q) {
            // car.drive(q);
            if(this->pass > 0){
                if(this->Fuel - q >= 0){
                    this->Fuel -= q;
                    this->km += q;
                }else if(this->Fuel == 0){
                    std::cout << "fail: tanque vazio" << std::endl;
                }else{
                    std::cout << "fail: tanque vazio apos andar "<<(this->Fuel)<<" km" << std::endl;
                    this->km += this->Fuel;
                    this->Fuel=0;
                }
            }else{
                std::cout << "fail: nao ha ninguem no carro" << std::endl;
            }
        }
        void show() {
            // std::cout << car.str() << std::endl;
            std::cout << "pass: " << this->pass << ", gas: " << this->Fuel << ", km: " << this->km << std::endl;  
        }
};

struct Debug {
    // Se a variável debug for true, os testes não serão executados
    // Apenas o conteúdo do método run() será executado
    // Você pode usar isso para testar seu código manualmente
    static const bool debug = false;
    static void run() {
        std::cout << "Debug ativado" << std::endl;
    }
};
