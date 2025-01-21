#pragma once
#include "fn.hpp"
class Pessoa{
    private:
        std::string nome;
    public:
        Pessoa(std::string nome){
            this->nome = nome;
        }
        std::string getNome(){
            return this->nome;
        }
        void setNome(std::string nome){
            this->nome = nome;
        }
};

class Mercantil{
    private:
        std::vector<Pessoa> caixas;
        std::list<Pessoa> espera;
        bool validarIndice(int indice){
            return indice >= 0 && indice < int(caixas.size());
        }
    public:
        Mercantil(int qtd_caixas=0){
            for(int i = 0; i < qtd_caixas; i++){
                this->caixas.push_back(Pessoa(""));
            }
            this->espera = std::list<Pessoa>();
        }
        std::string toString(){
            std::string str;
            str += "Caixas: [";
            for(int i = 0; i < int(this->caixas.size()); i++){
                if(this->caixas[i].getNome() != ""){
                    str += caixas[i].getNome() + "";
                }else{
                    str += "-----";
                }
                if(i < int(this->caixas.size() - 1)){
                    str += ", ";
                }
            }
            str += "]\n";
            str += "Espera: [";
            for(std::list<Pessoa>::iterator it = this->espera.begin(); it != this->espera.end(); it++){
                str += it->getNome();
                if(std::next(it) != this->espera.end()){
                    str += ", ";
                }
            }
            str += "]";
            return str;
        }
        void chegar(Pessoa pessoa){
            this->espera.push_back(pessoa);
        }
        void chamar(int indice){
            if(validarIndice(indice)){
                if(this->caixas[indice].getNome() == ""){
                    if(this->espera.size() > 0){
                        this->caixas[indice] = this->espera.front();
                        this->espera.pop_front();
                    }else{
                        std::cout << "fail: sem clientes" << std::endl;
                    }
                }else{
                    std::cout << "fail: caixa ocupado" << std::endl;
                }
            }else{
                std::cout << "fail: caixa inexistente" << std::endl;
            }
        }
        Pessoa finalizar(int indice){
            if(validarIndice(indice)){
                if(this->caixas[indice].getNome() == ""){
                    std::cout << "fail: caixa vazio" << std::endl;
                    return Pessoa("");
                }else{
                    Pessoa pessoa = this->caixas[indice];
                    this->caixas[indice] = Pessoa("");
                    return pessoa;
                }
            }else{
                std::cout << "fail: caixa inexistente" << std::endl;
                return Pessoa("");
            }
        }

        bool furarFila(Pessoa furao, std::string besta){
            for(std::list<Pessoa>::iterator it = this->espera.begin(); it != this->espera.end(); it++){
                if(it->getNome() == besta){
                    this->espera.insert(it, furao);
                    return true;
                }
            }
            return false;
        }

        bool desistir(const std::string& desistente) {
        for (auto it = espera.begin(); it != espera.end(); ++it) {
            if (it->getNome() == desistente) {
                espera.erase(it);
                return true;
            }
        }
        return false;
    }
        bool revoltar(std::string nome){
            for(int i = 0; i < int(this->caixas.size()); i++){
                if(this->caixas[i].getNome() == nome){
                    this->caixas[i] = Pessoa("");
                    return true;
                }
            }
            return false;
        }

};

class Adapter {
public:
    Adapter() {
    }
    Mercantil mercantil;
    void init(int qtd_caixas) {
        mercantil = Mercantil(qtd_caixas);
    }
    void call(int indice) {
        mercantil.chamar(indice);
    }
    void finish(int indice) {
        mercantil.finalizar(indice);
    }
    void arrive(const std::string& nome) {
        mercantil.chegar(Pessoa(nome));
    }

    std::string str() {
        return mercantil.toString();
    }
};

struct Student {
    // Se a variável debug for true, os testes não serão executados
    // Apenas o conteúdo do método run() será executado
    // Você pode usar isso para testar seu código manualmente
    static const bool debug = false;
    static void run() {
    }
};
