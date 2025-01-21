#include <iostream>
#include <limits>
using namespace std;

class Chinela {
private:
    int tamanho;

public:
    Chinela(){
        tamanho = 0;
    }

    int getTamanho() const {
        return tamanho;
    }

    void setTamanho(int valor) {
        if (valor >= 20 && valor <= 50 && valor % 2 == 0) {
            tamanho = valor;
        } else {
            cout << "Erro: O tamanho deve ser um número par entre 20 e 50." << endl;
        }
    }
};

int main() {
    Chinela chinela;

    while (chinela.getTamanho() == 0) {
        cout << "Digite seu tamanho de chinela (entre 20 e 50, números pares): ";
        int tamanho;
        cin >> tamanho;

        if (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Erro: Por favor, insira um número válido." << endl;
        } else {
            chinela.setTamanho(tamanho);
        }
    }

    cout << "Tamanho de chinela escolhido: " << chinela.getTamanho() << endl;
    return 0;
}
