#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

template <class CONTAINER, class FUNC>
string map_join(const CONTAINER &cont, FUNC func, string sep = " ")
{
    stringstream ss;
    for (auto it = cont.begin(); it != cont.end(); it++)
    {
        ss << (it == cont.begin() ? "" : sep) << func(*it);
    }
    return ss.str();
}

class Fone{
    private:
        string operadora;
        int id;
        string number;
    public:
        Fone(int id, string operadora = "", string number = ""){
            this->id = id;
            this->operadora = operadora;
            this->number = number;
        }
        int getId(){
            return id;
        }
        string getNumber(){
            return number;
        }
        string toString(){
            return operadora + ":" + number;
        }
};

class Contato{
    private:
        string name;
        vector<Fone> fones;
        bool fav;
        int QtdNumeros=-1;
    public:
        Contato(string nome){
            this->name = nome;
            this->fav = false;
        }
        Contato(){
            this->name = "-";
            this->fav = false;
        }
        bool isValid(string number){
            for (char c : number)
            {
                if (!isdigit(c) && c != '(' && c != ')' && c != '.')
                    return false;
            }
            return true;
        }
        void addFone(string operadora, string number){
            if(!isValid(number)){
                cout << "fail: invalid number" << endl;
                return;
            }
            QtdNumeros++;
            fones.push_back(Fone(QtdNumeros, operadora, number));
        }
        void rmFone(int index){
            if(index < 0 || index >= (int) fones.size()){
                cout << "fail: indice invalido" << endl;
                return;
            }
            fones.erase(fones.begin() + index);
        }
        void toogleFav(){
            fav = !fav;
        }
        bool isFavorite(){
            return fav;
        }
        string getName(){
            return name;
        }
        int getQtdNumeros(){
            return QtdNumeros;
        }
        vector<Fone> getFones(){
            return fones;
        }
        void setName(string name){
            this->name = name;
        }
        string toString(){
            stringstream ss;
            ss << (fav ? "@ " : "- ") << name << " [";
            ss << map_join(fones, [](Fone fone) { return fone.toString(); }, ", ");
            ss << "]";
            return ss.str();
        }
};

int main()
{   
    Contato contato = Contato();
    while (true)
    {   
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;
        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end")
        {
            break;
        }
        else if (cmd == "init")
        {
            string name;
            ss >> name;
            contato = Contato(name);
        }
        else if (cmd == "add")
        {
            string id, number;
            ss >> id >> number;
            contato.addFone(id, number);

        }
        else if (cmd == "rm")
        {
            int index{};
            ss >> index;
            contato.rmFone(index);
        }
        else if (cmd == "tfav")
        {
            contato.toogleFav();
        }
        else if (cmd == "show")
        {
            cout << contato.toString() << endl;
        }
        else
        {
            cout << "fail: comando invalido" << endl;
        }
    }
}
