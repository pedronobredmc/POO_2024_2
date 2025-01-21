#include "fn.hpp"
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
            std::cout << "fail: Valor inválido, tente PP, P, M, G, GG ou XG\n";
        }
    }

    std::string getTamanho() const {
        return tamanho;
    }

    std::string toString() const {
        return "size: (" + tamanho + ")";
    }
};

class Adapter {
public:
    Roupa roupa;
    Adapter() {
    }
    void size(const std::string& size) {
        roupa.setTamanho(size);
    }
    void show() {
        std::cout << roupa.toString() << std::endl;
    }
};

int main() {
    Adapter adapter;
    while (true) {
        fn::write("$", "");
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write(line);

        if      (args[0] == "end")  { break;                         }
        else if (args[0] == "size") { adapter.size(args[1]);         }
        else if (args[0] == "show") { adapter.show();                }
        else                        { fn::write("Comando inválido"); }
    }
}