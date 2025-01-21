#include <iostream>
#include <memory>
#include <utility>
#include "fn.hpp"
class Bateria{
    private:
        int carga {0};
        int capacidade {0};
    public:
        Bateria(int capacidade=0){
            this->capacidade = capacidade;
            this->carga = capacidade;
        }
        int get_carga(){
            return this->carga;
        }
        void set_carga(int carga){
            this->carga = carga;
        }
        int get_capacidade(){
            return this->capacidade;
        }
};

class Carregador{
    private:
        int potencia {0};
    public:
        Carregador(int potencia=0){
            this->potencia = potencia;
        }
        void setPotencia(int potencia){
            this->potencia = potencia;
        }
        int getPotencia(){
            return this->potencia;
        }
};

class Notebook{
    private:
    Bateria bateria;
    Carregador carregador;
    bool ligado {false};
    int minutos_usados {0};
    public:
    void ligar() {
        if (ligado) {
            std::cout << "fail: Notebook já está ligado\n";
        } else {
            if(this->bateria.get_carga()>0){
                ligado = true;
            }else{
                if(carregador.getPotencia() > 0){
                    ligado = true;
                }else{
                    std::cout << "fail: não foi possível ligar\n";
                }
            }
                
        }
    }

    void desligar() {
        if (ligado) {
            ligado = false;
        } else {
            std::cout << "fail: Notebook já está desligado\n";
        }
    }

    bool isLigado() {
        return ligado;
    }

    void usar(int minutos) {
        if (ligado) {
            if(this->bateria.get_carga() > 0 && this->carregador.getPotencia() == 0){
                if(this->bateria.get_carga() - minutos <= 0){
                    minutos = this->bateria.get_carga();
                    std::cout << "fail: descarregou\n";
                    this->ligado = false;
                }
                this->bateria.set_carga(this->bateria.get_carga() - minutos);
            }
            minutos_usados += minutos;
            if(carregador.getPotencia() > 0){
                this->bateria.set_carga(this->bateria.get_carga() + minutos*carregador.getPotencia());
                if(this->bateria.get_carga() > this->bateria.get_capacidade()){
                    this->bateria.set_carga(this->bateria.get_capacidade());
                }
            }
        } else {
            std::cout << "fail: desligado\n";
        }
    }

    void setCarregador(int potencia) {
        if(this->carregador.getPotencia() == 0){
            this->carregador.setPotencia(potencia);
        }else{
            std::cout << "fail: carregador já conectado\n";
        }
    }

    void removeCarregador() {
        if(this->carregador.getPotencia() > 0){
            std::cout << "Removido " << this->carregador.getPotencia() << "W\n";
            this->carregador.setPotencia(0);
            if(this->bateria.get_carga() == 0){
                this->ligado = false;
            }
        }else{
            std::cout << "fail: Sem carregador\n";
        }
    }

    void removeBateria() {
        if(this->bateria.get_carga() > 0){
            auto bateria = this->bateria;
            this->bateria = Bateria();
            std::cout << "Removido " << bateria.get_carga() << "/" << bateria.get_capacidade() << '\n';
            if(this->carregador.getPotencia() == 0){
                this->ligado = false;
            }
        }else{
            std::cout << "fail: Sem bateria\n";
        }
    }

    void setBateria(int capacidade) {
        this->bateria = Bateria(capacidade);
    }

    std::string str(){
        if (this->carregador.getPotencia() == 0) {
            if(this->bateria.get_carga() == 0){
                if(minutos_usados > 0 && bateria.get_capacidade() > 0){
                    return "Notebook: " + std::string(ligado ? "ligado" : "desligado") + ", Bateria " + std::to_string(this->bateria.get_carga()) + "/" + std::to_string(this->bateria.get_capacidade());
                }else{
                    return "Notebook: " + std::string(ligado ? "ligado" : "desligado");
                }
            }else{
                if(!isLigado()){
                    return "Notebook: " + std::string(ligado ? "ligado" : "desligado") + ", Bateria " + std::to_string(this->bateria.get_carga()) + "/" + std::to_string(this->bateria.get_capacidade());
                }else{
                    return "Notebook: " + std::string(ligado ? "ligado" : "desligado") + " por " + std::to_string(minutos_usados) + " min, Bateria " + std::to_string(this->bateria.get_carga()) + "/" + std::to_string(this->bateria.get_capacidade());
                }
            }
        }else if(this->carregador.getPotencia() > 0 && this->bateria.get_carga() == 0){
            if (!isLigado()) {
                return "Notebook: " + std::string(ligado ? "ligado" : "desligado") + ", Carregador " + std::to_string(this->carregador.getPotencia()) + "W";
            } else {
                return "Notebook: " + std::string(ligado ? "ligado" : "desligado") + " por " + std::to_string(minutos_usados) + " min, Carregador " + std::to_string(this->carregador.getPotencia()) + "W";
            }
        }else{
            if(!isLigado()){
                return "Notebook: " + std::string(ligado ? "ligado" : "desligado") + ", Carregador " + std::to_string(this->carregador.getPotencia()) + "W" + ", Bateria " + std::to_string(this->bateria.get_carga()) + "/" + std::to_string(this->bateria.get_capacidade());
            }else{
                return "Notebook: " + std::string(ligado ? "ligado" : "desligado") + " por " + std::to_string(minutos_usados) + " min, Carregador " + std::to_string(this->carregador.getPotencia()) + "W" + ", Bateria " + std::to_string(this->bateria.get_carga()) + "/" + std::to_string(this->bateria.get_capacidade());
            }
        }
    }
};

class Adapter {
    Notebook notebook;
public:
    void show() {
        std::cout << notebook.str() << '\n';
    }

    void turn_on() {
        notebook.ligar();
    }

    void turn_off() {
        notebook.desligar();
    }

    void set_charger(int power) {
        notebook.setCarregador(power);
    }
    void rm_charger() {
        notebook.removeCarregador();
    }
    void set_battery(int capacity) {
        notebook.setBateria(capacity);
    }

    void rm_battery() {
        notebook.removeBateria();
    }

    void use(int minutes) {
        notebook.usar(minutes);
    }
};

int main() {
    Adapter adp;
    while (true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write("$" + line);

        if      (args[0] == "end")         { break;                                   }
        else if (args[0] == "show")        { adp.show();                              }
        else if (args[0] == "turn_on")     { adp.turn_on();                           }
        else if (args[0] == "turn_off")    { adp.turn_off();                          }
        else if (args[0] == "use")         { adp.use(+args[1]);                       }
        else if (args[0] == "set_charger") { adp.set_charger(+args[1]);               }
        else if (args[0] == "rm_charger")  { adp.rm_charger();                        }
        else if (args[0] == "set_battery") { adp.set_battery(+args[1]);               }
        else if (args[0] == "rm_battery")  { adp.rm_battery();                        }
        else                               { std::cout << "fail: comando inválido\n"; }
    }    
}
