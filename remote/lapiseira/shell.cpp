#include "fn.hpp"

class Grafite{
    private:
    std::string dureza;
    float calibre;
    int tamanho;
    public:
    Grafite(float calibre, std::string dureza, int tamanho){
        this->calibre = calibre;
        this->dureza = dureza;
        this->tamanho = tamanho;
    }

    int usagePerSheet(){
        if(dureza == "HB") return 1;
        if(dureza == "2B") return 2;
        if(dureza == "4B") return 4;
        if(dureza == "6B") return 6;
        return 0;
    }

    int getSize(){
        return this->tamanho;
    }

    float getCalibre(){
        return this->calibre;
    }

    std::string getDureza(){
        return this->dureza;
    }

    void setSize(int tamanho){
        this->tamanho = tamanho;
    }

    std::string str() const {
        std::ostringstream os;
        os << std::fixed << std::setprecision(1) << calibre << ":" << dureza << ":" << tamanho;
        return os.str();
    }
};

class Lapiseira {
    private:
    float calibre{0.f};
    std::shared_ptr<Grafite> bico {nullptr};
    std::vector<std::shared_ptr<Grafite>> estojo;
    public:
    Lapiseira(float calibre=0.0){
        this->calibre = calibre;
    }

    bool inserir(std::shared_ptr<Grafite> grafite){
        if(this->calibre != grafite->getCalibre()){
            std::cout << "fail: calibre incompatível" << std::endl;
            return false;
        }
        this->estojo.push_back(grafite);
        return true;
    }

    std::shared_ptr<Grafite> remover(){
        if(this->bico != nullptr){
            std::shared_ptr<Grafite> grafite_aux = this->bico;
            this->bico = nullptr;
            return grafite_aux;
        }
        return nullptr;
    }

    void puxar(){
        if(!this->estojo.empty()){
            std::shared_ptr<Grafite> grafite_aux = this->estojo.front();
            if(this->bico == nullptr){
                this->bico = grafite_aux;
                this->estojo.erase(this->estojo.begin());
            }else{
                std::cout << "fail: ja existe grafite no bico" << std::endl;
                return;
            }
        }
    }

    void write() {
      if(this->bico == nullptr){
        std::cout<< "fail: nao existe grafite no bico" << std::endl;
      }else{
        if(this->bico->getSize()<= 10){
          std::cout<< "fail: tamanho insuficiente" << std::endl;
          return;
        }else if(this->bico->getSize() > 10 && (this->bico->getSize() < this->bico->usagePerSheet() + 10)){
          std::cout<< "fail: folha incompleta" << std::endl;
          this->bico->setSize(10);
        }else{
          this->bico->setSize(this->bico->getSize() - this->bico->usagePerSheet());
        }
      }
      
    }

    std::string str() const {
        auto fngr = [](std::shared_ptr<Grafite> g) { return "[" + (g == nullptr ? "" : g->str()) + "]"; };
        std::ostringstream os;
        os << "calibre: " << calibre 
           << ", bico: " << fngr(bico)
           << ", tambor: <";

        for (const auto& g : estojo) {
            os << fngr(g);
        }

        os << ">";
        return os.str();
    }

};

class Adapter {
    public:
    Lapiseira lapiseira;

    void show() {
        std::cout << lapiseira.str() << std::endl;
    }

    void init(float calibre) {
        (void) calibre;
        lapiseira = Lapiseira(calibre);
    }

    void insert(float calibre, std::string dureza, int tamanho) {
        lapiseira.inserir(std::make_shared<Grafite>(calibre, dureza, tamanho));
    }

    void remove() {
        lapiseira.remover();
    }

    void pull() {
        lapiseira.puxar();
    }

    void write() {
        lapiseira.write();
    }

};

int main() {
    Adapter adp;
    while (true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write("$" + line);

        if (args[0] == "end") { break; }
        else if (args[0] == "show") { adp.show(); }
        else if (args[0] == "init") { adp.init((float) +args[1]); }
        else if (args[0] == "insert") { adp.insert((float) +args[1], args[2], +args[3]); }
        else if (args[0] == "remove") { adp.remove(); }
        else if (args[0] == "pull") { adp.pull(); }
        else if (args[0] == "write") { adp.write(); }
        else { fn::write("fail: comando invalido"); }
    }
}
