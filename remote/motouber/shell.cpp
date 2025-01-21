#include <iostream>
#include "fn.hpp"

class Pessoa{
    private:
        std::string pessoaNome;
        int dinheiro;
    public:
        Pessoa(){
            pessoaNome = "";
            dinheiro = 0;
        }
        void setNome(std::string nome){
            pessoaNome = nome;
        }
        void setDinheiro(int dinheiro){
            this->dinheiro = dinheiro;
        }
        std::string getNome(){
            return pessoaNome;
        }
        int getDinheiro(){
            return dinheiro;
        }
};


class MotoUber{
    private:
        Pessoa motorista;
        Pessoa passageiro;
        int custoAtualCorrida;
    public:
        MotoUber(){
            this->custoAtualCorrida = 0;
        }
        void setCustoAtualCorrida(int custo){
            this->custoAtualCorrida = custo;
        }
        int getCustoAtualCorrida(){
            return custoAtualCorrida;
        }
        void setDriver(std::string nome, int dinheiro){
            motorista.setNome(nome);
            motorista.setDinheiro(dinheiro);
        }
        void setPass(std::string nome, int dinheiro){
            passageiro.setNome(nome);
            passageiro.setDinheiro(dinheiro);
        }
        void descerPassageiro(){
            if(passageiro.getDinheiro()>=custoAtualCorrida){
                motorista.setDinheiro(motorista.getDinheiro()+custoAtualCorrida);
                passageiro.setDinheiro(passageiro.getDinheiro()-custoAtualCorrida);
                setCustoAtualCorrida(0);
                std::cout << passageiro.getNome() << ":" << passageiro.getDinheiro() << " leave\n";
                passageiro.setNome("");
            }else{
                std::cout << "fail: Passenger does not have enough money\n";
                motorista.setDinheiro(motorista.getDinheiro()+getCustoAtualCorrida());
                passageiro.setDinheiro(0);
                setCustoAtualCorrida(0);
                std::cout << passageiro.getNome() << ":" << passageiro.getDinheiro() << " leave\n";
                passageiro.setNome("");
            }
        }
        void drive(int distancia){
            custoAtualCorrida += distancia;
        }
        void show(){
            if(motorista.getNome() == "" && passageiro.getNome() == ""){
                std::cout << "Cost: " << getCustoAtualCorrida() << ", Driver: None"  << ", Passenger: None" << "\n";
            }else if(motorista.getNome() == "" && passageiro.getNome() != ""){
                std::cout << "Cost: " << getCustoAtualCorrida() << ", Driver: None"  << ", Passenger: " << passageiro.getNome() << ":" << passageiro.getDinheiro() << "\n";
            }else if(motorista.getNome() != "" && passageiro.getNome()==""){
                std::cout << "Cost: " << getCustoAtualCorrida() << ", Driver: " << motorista.getNome() << ":" << motorista.getDinheiro() << ", Passenger: None" << "\n";
            }else{
                std::cout << "Cost: " << getCustoAtualCorrida() << ", Driver: " << motorista.getNome() << ":" << motorista.getDinheiro() << ", Passenger: " << passageiro.getNome() << ":" << passageiro.getDinheiro() << "\n";
            }
        }

};

class Adapter {
public:
    MotoUber mu;
    void setDriver(std::string name, int money) {
        mu.setDriver(name, money);
    }
    void setPass(std::string name, int money) {
        mu.setPass(name, money);
    }
    void drive(int distance) {
        mu.drive(distance);
    }
    void leavePass() {
        mu.descerPassageiro();
    }
    void show() {
        mu.show();
    }
};

int main() {
    Adapter adp;
    while (true) {
        fn::write("$", "");
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write(line);

        if      (args[0] == "end")       { break;                                  }
        else if (args[0] == "setDriver") { adp.setDriver(args[1], +args[2]);       }
        else if (args[0] == "setPass")   { adp.setPass(args[1], +args[2]);         }
        else if (args[0] == "drive")     { adp.drive(+args[1]);                    }
        else if (args[0] == "leavePass") { adp.leavePass();                        }
        else if (args[0] == "show")      { adp.show();                             }
        else                             { fn::write("fail: command not found\n"); }
    }
}