#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

class Slot{
    private:
        std::string name{""};
        int quantity{0};
        float price{0};
    public:
        Slot(std::string name, float price, int quantity){
            this->name = name;
            this->price = price;
            this->quantity = quantity;
        }
        std::string getName() const{
            return this->name;
        }
        int getQuantity() const{
            return this->quantity;
        }
        float getPrice() const{
            return this->price;
        }
        void setQuantity(int quantity){
            this->quantity = quantity;
        }
        void setPrice(float price){
            this->price = price;
        }
        void setName(std::string name){
            this->name = name;
        }
};

class VendingMachine{
    private:
        std::vector<Slot> slots;
        float profit{0};
        float cash{0};
        int capacity{0};
    public:
        VendingMachine(int capacity){
            this->capacity = capacity;
            for(int i = 0; i < capacity; i++){
                slots.push_back(Slot("empty", 0, 0));
            }
        }
        Slot getSlot(int index) {
            if (index < 0 || index >= (int)slots.size()) {
                throw "fail: indice nao existe";
            }
            return slots[index];
        }
        void setSlot(int index, Slot slot) {
            if (index < 0 || index >= (int)slots.size()) {
                throw "fail: indice nao existe";
            }
            slots[index] = slot;
        }
        void clearSlot(int index) {
            if (index < 0 || index >= (int)slots.size()) {
                throw "fail: indice nao existe";
            }
            slots[index] = Slot("empty", 0, 0);
        }
        void insertCash(float cash){
            this->cash += cash;
        }
        void withdrawCash(){
            std::cout << "voce recebeu " << std::fixed << std::setprecision(2) << this->cash << " RS" << std::endl;
            this->cash = 0;
        }
        float getCash(){
            return this->cash;
        }
        float getProfit(){
            return this->profit;
        }
        void buy(int index) {
            if (index < 0 || index >= (int)slots.size()) {
                throw "fail: indice nao existe";
            }
            Slot slot = slots[index];
            if (slot.getQuantity() == 0) {
                throw "fail: espiral sem produtos";
            }
            if (this->cash < slot.getPrice()) {
                throw "fail: saldo insuficiente";
            }
            this->cash -= slot.getPrice();
            this->profit += slot.getPrice();
            slot.setQuantity(slot.getQuantity() - 1);
            slots[index] = slot;
            std::cout << "voce comprou um " << slot.getName() << std::endl;
        }
        std::string show() {
            std::ostringstream out;
            out << "saldo: " << std::fixed << std::setprecision(2) << this->cash << "\n";
            for (int i = 0; i < (int)slots.size(); ++i) {
                const auto& slot = slots[i];
                out << i << " ["
                    << std::setw(8) << std::right << slot.getName() << " : "
                    << slot.getQuantity() << " U : "
                    << std::fixed << std::setprecision(2) << slot.getPrice()
                    << " RS]";
                if (i != (int)slots.size() - 1) { 
                    out << "\n";
                }
            }

            return out.str();
        }
};

int main() {
    VendingMachine vm(0);
    while (true) {
        std::string line, cmd;
        getline(std::cin, line);
        std::cout << "$" << line << std::endl;

        std::stringstream ss(line);
        ss >> cmd;

        try {
            if (cmd == "show") {
                // IMPRIMIR
                std::cout << vm.show() << std::endl;
            } else if (cmd == "init") {
                int n_espirais {};
                ss >> n_espirais;
                vm = VendingMachine(n_espirais);
            } else if (cmd == "limpar") {
                int indice {};
                ss >> indice;
                vm.clearSlot(indice);
            } else if (cmd == "dinheiro") {
                int value {};
                ss >> value;
                vm.insertCash(value);
            } else if (cmd == "comprar") {
                int index {};
                ss >> index;
                vm.buy(index);
            } else if (cmd == "set") {
                int index {};
                std::string name;
                int qtd {};
                double price {};
                ss >> index >> name >> qtd >> price;
                Slot slot(name, price, qtd);
                vm.setSlot(index, slot);
            } else if (cmd == "troco") {
                vm.withdrawCash();
            } else if (cmd == "end") {
                break;
            } else {
                std::cout << "comando invalido" << std::endl;
            }
        } catch (const char* e) {
            std::cout << e << std::endl;
        }
    }
}
