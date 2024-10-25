#include <iostream>
#include <fstream>
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

int main(){
    dados_alunos aluno;
    aluno.construct_aluno("João Heric Campos", 6, 2022, "123.123.123-12", "528223");
    std::ofstream Myfile("teste2.txt");
    Myfile << aluno.name << '\n' << aluno.semestre << '\n' << aluno.ano_entrada << '\n' << aluno.GetCpf() << '\n' << aluno.GetMatricula() << '\n'; 
}