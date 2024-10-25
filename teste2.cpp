#include <iostream>

class dados_alunos{
    public:
        std::string name;
        int semestre;
        int ano_entrada;
        std::string GetCpf(){
            return CPF;
        }
        std::string GetMatricula(){
            return matricula;
        }
        void SetCpf(std::string cpf){
            this->CPF = cpf;
        }
        void SetMatricula(std::string matricula){
            this->matricula = matricula;
        }
        void construct_aluno(std::string name, int semestre, int ano_entrada, std::string cpf, std::string matricula){
            this->name=name;
            this->semestre=semestre;
            this->ano_entrada=ano_entrada;
            this->CPF=cpf;
            this->matricula=matricula;
        }
    private:
        std::string CPF;
        std::string matricula;
};