#include <iostream>
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
            if(this->pass > this->passMax){
                std::cout <<"fail: limite de pessoas atingido.\n";
            }else{
                this->pass++;
            }
        }
        void leave(){
            if(this->pass <= 0){
                std::cout <<"fail: nao ha ninguem no carro.\n";
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
            if(this->gas<0 && this->pass>0){
                this->gas=this->gas-dist;
                this->km+=dist;
            }else if(this->gas<0){
                std::cout<<"fail: tanque vazio\n";
            }else if(this->pass<0){
                std::cout<<"fail: nao ha ninguem no carro\n";
            }else if(this->gas<dist){
                std::cout<<"fail: tanque vazio após andar "<<std::to_string((dist)-(this->gas))<<" km.\n";
            }
        }
};

int main(){
    car c;
    c.construct_car(0, 2, 0, 100, 0);

}