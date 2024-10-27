#include <fn.hpp>
#include <algorithm>
using namespace fn;

class fila{
    public:
        bool in(std::vector<int> estresse, int n){
            for(int i=0; i<estresse.size(); i++){
                if(estresse[i]==n){
                    return true;
                }
            }
            return false;
        }
        int index_of(std::vector<int> estresse, int n){
            for(int i=0; i<estresse.size(); i++){
                if(estresse[i]==n){
                    return i;
                }
            }
            return -1;
        }
        int find_if(std::vector<int> estresse){
            for(int i=0; i<estresse.size(); i++){
                if(estresse[i]>0){
                    return i;
                }
            }
            return -1;
        }
        int min_element(std::vector<int> estresse){
            int min=estresse[0];
            for(int i=1; i<estresse.size(); i++){
                if(std::abs(estresse[i])<std::abs(min)){
                    min=estresse[i];
                }
            }
            return min;
        }
        int find_min_if(std::vector<int> estresse){
            int min = estresse[0];
            for(int i=1; i<estresse.size(); i++){
                if(estresse[i]>0 && estresse[i]<min){
                    min=estresse[i];
                }
            }
        }
};

auto STRTOVET = [](auto s) {
    s = s.substr(1, s.size() - 2);
    std::vector<int> result;
    std::stringstream ss(s);
    std::string item;

    while (std::getline(ss, item, ',')) {
        result.push_back(std::stoi(item));
    }

    return result;
};

int main() {

    fila f;

    while (true) {
        auto line = input();
        write("$" + line);
        auto args = split(line);

        if      (args[0] == "end"        ) { break;                                              }
        else if (args[0] == "in"         ) { write(tostr(f.in(STRTOVET(args[1]), +args[2])));    }
        else if (args[0] == "index_of"   ) { write(f.index_of(STRTOVET(args[1]), +args[2]));     }
        else if (args[0] == "find_if"    ) { write(f.find_if(STRTOVET(args[1])));                }
        else if (args[0] == "min_element") { write(f.min_element(STRTOVET(args[1])));            }
        else if (args[0] == "find_min_if") { write(f.find_min_if(STRTOVET(args[1])));            }
        else                               { write("fail: unknown command");                     }
    }
  
    
}