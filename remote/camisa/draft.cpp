#include <iostream>

int main() {
    std::cout << "qxcode\n";
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Roupa {
private:
    std::string tamanho;
    const std::vector<std::string> tamanhosValidos = {"PP", "P", "M", "G", "GG", "XG"};

public:
    Roupa() : tamanho("") {}

    void setTamanho(const std::string& novoTamanho) {
        if (std::find(tamanhosValidos.begin(), tamanhosValidos.end(), novoTamanho) != tamanhosValidos.end()) {
            tamanho = novoTamanho;
        } else {
            std::cerr << "Erro: Tamanho invalido. Valores permitidos: PP, P, M, G, GG, XG.\n";
        }
    }

    std::string getTamanho() const {
        return tamanho;
    }
};

int main() {
    Roupa roupa;
    std::string tamanhoInserido;

    std::cout << "O tamanho inicial da roupa e vazio (nenhum tamanho definido).\n";

    do {
        std::cout << "Por favor, insira o tamanho da roupa (PP, P, M, G, GG, XG): ";
        std::cin >> tamanhoInserido;

        roupa.setTamanho(tamanhoInserido);

        if (roupa.getTamanho() != "") {
            std::cout << "Tamanho definido com sucesso: " << roupa.getTamanho() << "\n";
        } else {
            std::cout << "Tente novamente.\n";
        }
    } while (roupa.getTamanho() == "");

    return 0;
}