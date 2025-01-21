#include <iostream>
#include <vector>
#include <sstream>
#include <memory>
using namespace std;

template<class CONTAINER, class FUNC>
string map_join(const CONTAINER& c, FUNC f, string sep) {
    stringstream ss;
    for (auto it = c.begin(); it != c.end(); it++) {
        ss << (it == c.begin() ? "" : sep);
        ss << f(*it);
    }
    return ss.str();
}

class Client{
    private:
        std::string id{""};
        int phone{0};
    public:
        Client(std::string id, int phone){
            this->id = id;
            this->phone = phone;
        }
        int getPhone(){
            return phone;
        }
        std::string getId(){
            return id;
        }
        void setPhone(int phone){
            this->phone = phone;
        }
        void setId(std::string id){
            this->id = id;
        }
        std::string toString(){
            return id + ":" + std::to_string(phone);
        }
};

class Theater{
    private:
        std::vector<Client> seats;
        bool searchId(std::string name){
            for(Client c : seats){
                if(c.getId() == name){
                    return true;
                }
            }
            return false;
        }
        bool verifyIndex(int index){
            if(index < 0 || index >= static_cast<int>(seats.size())){
                return false;
            }
            return true;
        }
    public:
        Theater(int capacity){
            for(int i = 0; i < capacity; i++){
                seats.push_back(Client("", 0));
            }
        }
        void reserve(std::string id, int phone, int index){
            if(!searchId(id)){
                if(verifyIndex(index)){
                    if(seats[index].getId()==""){
                        seats[index].setId(id);
                        seats[index].setPhone(phone);
                        return;
                    }else{
                        std::cout << "fail: cadeira ja esta ocupada" << std::endl;
                    }
                }else{
                    std::cout << "fail: cadeira nao existe" << std::endl;
                }
            }else{
                std::cout << "fail: cliente ja esta no cinema" << std::endl;
            }
        }
        void cancel(std::string id){
            for(Client& c : seats){
                if(c.getId() == id){
                    c.setId("");
                    c.setPhone(0);
                    return;
                }
            }
            std::cout << "fail: cliente nao esta no cinema" << std::endl;
            return;
        }
        std::vector<Client> getSeats(){
            return seats;
        }
        std::string toString(){
            std::vector<Client> aux = getSeats();
            std::vector<std::string> aux2;
            for(Client c : aux){
                if(c.getId() == ""){
                    aux2.push_back("-");
                }else{
                    aux2.push_back("" + c.toString());
                }
            }
            return "[" + map_join(aux2, [](std::string s){return s;}, " ") + "]";
        }
};

int main() {
    Theater theater(0);
    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end") {
            break;    
        } else if (cmd == "show") {
            std::cout << theater.toString() << std::endl;
        } else if (cmd == "init") {
            int qtd;
            ss >> qtd;
            theater = Theater(qtd);
        } else if (cmd == "reserve") {
            string id;
            int phone;
            int index;
            ss >> id >> phone >> index;
            theater.reserve(id, phone, index);
        } else if (cmd == "cancel") {
            string id;
            ss >> id;
            theater.cancel(id);
        } else {
            cout << "fail: comando invalido" << endl;
        }
    }
}
