#include "fn.hpp"
using namespace fn;
class Animal{
    public:
        std::string especie;
        std::string barulho;
        int idade;
        Animal(std::string especie = "", std::string barulho = ""){
            this->barulho = barulho;
            this->idade = 0;
            this->especie = especie;
        }

        void fazerBarulho(){
            if(this->idade>0 && this->idade<4){
                std::cout << this->barulho<< "\n";
            }else if(this->idade==0){
                std::cout << "---\n";
            }else{
                std::cout << "RIP\n";
            }
            
        }
        
        void envelhecer(int qnt){
            this->idade+=qnt;
            if(this->idade>=4){
                std::cout << "warning: "+this->especie+" morreu\n";
                this->idade=4;
            }
        }

        void show(){
            std::cout << this->especie + ":" + std::to_string(this->idade) + ":" + this->barulho<< "\n";
        }
};

int main(){
    Animal Stu("", "");
     while (true) {
        fn::write("$", "");
        auto line = fn::input();
        auto args = fn::split(line, ' ');

        fn::write(line); //test echo

        if      (args[0] == "end"  ) { break;                               }

        else if (args[0] == "init" ) { Stu = Animal(args[1], args[2]);     }
        else if (args[0] == "grow" ) { Stu.envelhecer(+args[1]);                  }
        else if (args[0] == "noise") { Stu.fazerBarulho();              }
        else if (args[0] == "show" ) { Stu.show();               }

        else                         { fn::write("fail: comando invalido"); }
    }

}