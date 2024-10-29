#include <fn.hpp>
using namespace fn;
class animal{
    public:
        std::string especie;
        int idade;
        std::string barulho;

};
class teste{
    public:
        animal a;
        teste construct_animal(std::string especie, std::string barulho){
                this->a.especie=especie;
                this->a.barulho=barulho;
                return *this;
            }
            std::string fazerBarulho(){
                return this->a.barulho;
            }
            std::string envelhecer(int qnt){
                if(a.idade>=4){
                    return "warning: "+this->a.especie+"morreu.\n";
                    this->a.idade=4;
                }else{
                    this->a.idade+=qnt;
                    return std::to_string(this->a.idade);
                }
            }
            std::string show(){
                return this->a.especie + ":" + std::to_string(this->a.idade) + ":" + this->a.barulho;
            }
};

int main(){
    teste a;

     while (true) {
        fn::write("$", "");
        auto line = fn::input();
        auto args = fn::split(line, ' ');

        fn::write(line); //test echo

        if      (args[0] == "end"  ) { break;                               }

        else if (args[0] == "init" ) { a = a.construct_animal(args[1], args[2]);     }
        else if (args[0] == "grow" ) { a.envelhecer(+args[1]);                  }
        else if (args[0] == "noise") { a.fazerBarulho();              }
        else if (args[0] == "show" ) { a.show();               }

        else                         { fn::write("fail: comando invalido"); }
    }

}