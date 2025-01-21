#include "fn.hpp"
class Towel{
    private:
        std::string color;
        std::string size;
        int wetness;
    public:
        Towel(std::string color = "", std::string size = ""){
            this->color = color;
            this->size = size;
            this->wetness = 0;
        }
        void dry(int amount){
            if(this->size == "P" && wetness+amount >= 10){
                std::cout << "toalha encharcada" << std::endl;
                if(wetness+amount == 10){
                    this->wetness = 10;
                }
            }else if(this->size == "M" && wetness+amount >= 20){
                std::cout << "toalha encharcada" << std::endl;
                if(wetness+amount == 20){
                    this->wetness = 20;
                }
            }else if(this->size == "G" && wetness+amount >= 30){
                std::cout << "toalha encharcada" << std::endl;
                if(wetness+amount == 30){
                    this->wetness = 30;
                }
            }else{
                this->wetness += amount;
            }
        }
        bool is_dry(){
            return this->wetness == 0;
        }
        void show() const{
            std::cout << "Cor: " << this->color << ", Tamanho: " << this->size << ", Umidade: " << this->wetness << std::endl;
        }
        void wringOut(){
            this->wetness = 0;
        }
};

class Adapter {
public:
    Adapter() {}
    Towel toalha;
    void criar(const std::string& cor, const std::string& tamanho) {
        toalha = Towel(cor, tamanho);
    }

    void enxugar(int quantidade) {
        toalha.dry(quantidade);
    }

    void seca() {
        if(toalha.is_dry()){
            std::cout << "sim" << std::endl;
        }else{
            std::cout << "nao" << std::endl;
        }
    }

    void torcer() {
        toalha.wringOut();
    }

    void mostrar() const {
        toalha.show();
    }
};

int main() {
    Adapter adapter;
    while (true) {
        fn::write("$", "");
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write(line);

        if      (args[0] == "end"    ) { break;                           }
        else if (args[0] == "criar"  ) { adapter.criar(args[1], args[2]); }
        else if (args[0] == "enxugar") { adapter.enxugar(+args[1]);       }
        else if (args[0] == "seca"   ) { adapter.seca();                  }
        else if (args[0] == "torcer" ) { adapter.torcer();                }
        else if (args[0] == "mostrar") { adapter.mostrar();               }
        else                           { fn::write("comando invalido");   }
    }
}
