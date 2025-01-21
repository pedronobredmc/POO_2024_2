#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>


class Player{
    private:
        int label{0};
        int pos{0};
        bool free{true};
    public:
        Player(int label){
            this->label = label;
            this->pos = 0;
        }
        bool isFree(){
            return free;
        }
        void setFree(bool free){
            this->free = free;
        }
        int getLabel() const{
            return label;
        }
        int getPos() const{
            return pos;
        }
        void setPos(int pos){
            this->pos = pos;
        }
        std::string toString() const{
            std::string out = "player";
            out += std::to_string(this->label);
            out += ": ";
            return out;
        }
};

class Board{
    private:
        std::vector<int> trapList;
        std::vector<Player> players;
        int boardSize{0};
        bool running{true};
        int currentPlayer{0};
    public:
        Board(int nPlayers, int boardSize){
            this->boardSize = boardSize;
            for(int i=1; i<=nPlayers; i++){
                players.push_back(Player(i));
            }
        }
        void addTrap(int pos){
            trapList.push_back(pos);
        }
        void rollDice(int value){
            if(!this->running){
                std::cout << "game is over" << std::endl;
                return;
            }else{
                Player& player = players[currentPlayer];
                if(player.isFree()){
                    player.setPos(player.getPos() + value);
                    if(player.getPos() >= boardSize){
                        std::cout << "player" << player.getLabel() << " ganhou" << std::endl;
                        this->running = false;
                    }else{
                        std::cout << "player" << player.getLabel() << " andou para " << player.getPos() << std::endl;
                        if(std::find(trapList.begin(), trapList.end(), player.getPos()) != trapList.end()){
                            player.setFree(false);
                            std::cout << "player" << player.getLabel() << " caiu em uma armadilha" << std::endl;
                        }
                        currentPlayer = (currentPlayer + 1) % players.size();
                    }
                }else{
                    if(value % 2 == 0){
                        player.setFree(true);
                        std::cout << "player" << player.getLabel() << " se libertou"  << std::endl;
                    }else{
                        std::cout << "player" << player.getLabel() << " continua preso" << std::endl;
                    }
                    currentPlayer = (currentPlayer + 1) % players.size();
                }
            }
        }
        std::string toString() {
            std::ostringstream out;
            for (const auto& player : players) {
                out << "player" << player.getLabel() << ": ";
                for (int i = 0; i <= boardSize; i++) {
                    if (i == player.getPos()) {
                        out << player.getLabel();
                    } else if(i == boardSize && player.getPos() >= boardSize) {
                        out << player.getLabel();
                    }else{
                        out << ".";
                    }
                }
                out << "\n";
            }
            out << "traps__: ";
            for (int i = 0; i <= boardSize; i++) {
                out << (std::find(trapList.begin(), trapList.end(), i) != trapList.end() ? "x" : ".");
            }
            
            return out.str();
        }

};


int main() {
    Board board = Board(0, 0);
    while(true) {
        std::string line, cmd;
        getline(std::cin, line);
        std::cout << "$" << line << std::endl;

        std::stringstream ss(line);
        ss >> cmd;

        if (cmd == "end") {
            break;
        } else if (cmd == "init") {
            int nPlayers, size;
            ss >> nPlayers >> size;
            board = Board(nPlayers, size);
        } else if (cmd == "addTrap") {
            int pos;
            ss >> pos;
            board.addTrap(pos);
        } else if (cmd == "roll") {
            int value;
            ss >> value;
            board.rollDice(value);
        } else if (cmd == "show") {
            std::cout << board.toString() << std::endl;
        } else {
            std::cout << "fail: command not found" << std::endl;
        }
    }
}
