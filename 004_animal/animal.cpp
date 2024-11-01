#include <fn.hpp>
using namespace fn;
class Animal{
    public:
        std::string especie;
        int idade;
        std::string barulho;

        Animal(std::string especie, std::string barulho){
            this->barulho = barulho;
            this->idade = 0;
            this->especie = especie;
        }

        std::string fazerBarulho(){
            return this->barulho;
        }
        std::string envelhecer(int qnt){
            if(this->idade>=4){
                return "warning: "+this->especie+"morreu.\n";
                this->idade=4;
            }else{
                this->idade+=qnt;
                return std::to_string(this->idade);
            }
        }
        std::string show(){
            return this->especie + ":" + std::to_string(this->idade) + ":" + this->barulho;
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