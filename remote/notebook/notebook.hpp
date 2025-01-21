#pragma once
#include <iostream>

class Bateria {
    private:
        int carga;
        int capacidade;
    public:
        Bateria(int carga=0, int capacidade=0){
            this->carga = carga;
            this->capacidade = capacidade;
        }

        int getCarga(){
            return this->carga;
        }

        int getCapacidade(){
            return this->capacidade;
        }

        void setCarga(int carga){
            this->carga = carga;
        }

        void setCapacidade(int capacidade){
            this->capacidade = capacidade;
        }
};

class Carregador{
    private:
        int potencia;
        bool conectado = false;
    public:
        Carregador(int potencia=0){
            this->potencia = potencia;
        }

        int getPotencia(){
            return this->potencia;
        }

        void setPotencia(int potencia){
            this->potencia = potencia;
        }

        bool getConectado(){
            return this->conectado;
        }

        void conectar(){
            this->conectado = true;
        }
};

class Notebook{
    private:
        Carregador carregador = Carregador();
        Bateria bateria = Bateria();
        bool ligado = false;
    public:
        Notebook(int carga=0, int capacidade=0, int potencia=0){
            this->bateria = Bateria(carga, capacidade);
            this->carregador = Carregador(potencia);
            this->ligado = false;
        }

        void ligar(){
            if(this->isLigado()){
                std::cout << "fail: notebook ja esta ligado" << std::endl;
            }else if(this->bateria.getCarga() > 0){
                this->ligado = true;
            }else if(this->carregador.getConectado()){
                this->ligado = true;
            }else{
                std::cout << "fail: bateria insuficiente ou carregador desconectado" << std::endl;
            }
        }

        void desligar(){
            if(this->isLigado()){
                this->ligado = false;
            }else{
                std::cout << "fail: notebook desligado" << std::endl;
            }
        }

        void usar(int carga){
            if(this->ligado){
                if(this->bateria.getCarga() - carga >= 0){
                    this->bateria.setCarga(this->bateria.getCarga() - carga);
                }else if(carregador.getConectado()){
                    //usar enquanto carrega
                }
            }else{
                std::cout << "fail: notebook desligado" << std::endl;
            }
        }

        void carregar(int carga){
            if(carregador.getConectado()){
                if(this->bateria.getCarga() + carga <= this->bateria.getCapacidade()){
                    this->bateria.setCarga(this->bateria.getCarga() + (carga * carregador.getPotencia()));
                }else{
                    this->bateria.setCarga(this->bateria.getCapacidade());
                }
            }
        }

        int getCarga(){
            return this->bateria.getCarga();
        }

        int getCapacidade(){
            return this->bateria.getCapacidade();
        }

        bool isLigado(){
            return this->ligado;
        }

        void conectarCarregador(){
            if(this->carregador.getConectado()){
                std::cout << "fail: carregador ja conectado" << std::endl;
            }else{
                this->carregador.conectar();
            }
        }

        void desconectarCarregador(){
            if(this->carregador.getConectado()){
                this->carregador.conectar();
            }else{
                std::cout << "fail: carregador desconectado" << std::endl;
            }
        }

        std::string toString(){
            return "bateria: " + std::to_string(this->bateria.getCarga()) + "/" + std::to_string(this->bateria.getCapacidade()) + ", carregador: " + std::to_string(this->carregador.getPotencia()) + ", ligado: " + std::to_string(this->ligado);
        }
};