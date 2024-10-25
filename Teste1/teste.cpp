#include <iostream>
#include <fstream>
class maumau {
    public:
        std::string nome;
        int idade;
        maumau(std::string nome, int idade, std::string CPF, int matricula){
            this->nome = nome;
            this->idade = idade;
            this->CPF = CPF;
            this->Matricula = matricula;
        }

        std::string GetCPF(){
            return CPF;
        }
        int GetMatricula(){
            return Matricula;
        }
        void SetCPF(std::string CPF){
            this->CPF = CPF;
        }
        void SetMatricula(int Matricula){
            this->Matricula = Matricula;
        }
    private:
        std::string CPF;
        int Matricula;
};

int main(){
    maumau William("William", 20, "12312312312", 538462);
    maumau Maumau("Mauricio", 20, "12312312312", 548318);
    //std::cout << William.GetCPF() << std::endl;
    //std::cout << Maumau.GetMatricula() << std::endl;
    //std::cout << William.nome << std::endl;
    std::ofstream MyFile("teste.txt");
    MyFile << Maumau.nome << '\n' << Maumau.idade << '\n' << Maumau.GetCPF() << '\n'  << Maumau.GetMatricula() << '\n';
    MyFile.close();
}