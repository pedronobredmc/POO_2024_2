#pragma once
#include "fn.hpp"

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

struct Debug {
    // Se a variável debug for true, os testes não serão executados
    // Apenas o conteúdo do método run() será executado
    // Você pode usar isso para testar seu código manualmente
    static const bool debug = false;
    static void run() {
        std::cout << "Debug ativado" << std::endl;
    }
};