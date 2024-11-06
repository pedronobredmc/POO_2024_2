#include "fn.hpp"
using namespace fn;
class car{
    public:
        int pass;
        int passMax;
        int gas;
        int gasMax;
        int km;
        void construct_car(int Pass, int PassMax, int Gas, int GasMax, int Km){
            this->pass=Pass;
            this->passMax=PassMax;
            this->gas=Gas;
            this->gasMax=GasMax;
            this->km=Km;
        }
        void enter(){
            if(this->pass > this->passMax || this->pass==this->passMax){
                std::cout <<"fail: limite de pessoas atingido\n";
            }else{
                this->pass++;
            }
        }
        void leave(){
            if(this->pass == 0){
                std::cout <<"fail: nao ha ninguem no carro\n";
            }else{
                this->pass--;
            }
        }
        void fuel(int gas){
            if(this->gas+gas>=this->gasMax){
                this->gas=this->gasMax;
            }else{
                this->gas+=gas;
            }
        }
        void drive(int dist){
            if(this->gas<dist && this->gas!=0){
                std::cout<<"fail: tanque vazio apos andar "<<std::to_string(this->gas)<<" km\n";
                if(this->gas-dist<0){
                    this->km+=this->gas;
                    this->gas=0;
                }
                this->gas=0;
            }else if(this->gas<=0){
                std::cout<<"fail: tanque vazio\n";
            }else if(this->pass<=0){
                std::cout<<"fail: nao ha ninguem no carro\n";
            }else if(this->gas>0 && this->pass>0){
                this->gas=this->gas-dist;
                this->km+=dist;
            }
        }
        std::string show(){
            return "pass: " + std::to_string(pass) + ", gas: " + std::to_string(gas) + ", km: " + std::to_string(km);
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
