#include <iostream>
#include <memory>
#include <sstream>
#include <list>

template<class CONTAINER, class FUNC>
std::string map_join(const CONTAINER& c, FUNC f, std::string sep) {
    std::stringstream ss;
    for (auto it = c.begin(); it != c.end(); it++) {
        ss << (it == c.begin() ? "" : sep);
        ss << f(*it);
    }
    return ss.str();
}

class Kid {
    private:
        std::string name;
        int age;
    public:
        Kid(std::string name, int age){
            this->name = name;
            this->age = age;
        }
        std::string getName() {
            return name;
        }
        int getAge() {
            return age;
        }
        std::string toString() {
            return name + ":" + std::to_string(age);
        }
};

class Trampoline{
    private:
        std::list<Kid> playing;
        std::list<Kid> waiting;
        bool removeFromList(std::string name, std::list<Kid>&){
            for (auto it = playing.begin(); it != playing.end(); it++) {
                if (it->getName() == name) {
                    playing.erase(it);
                    return true;
                }
            }
            for (auto it = waiting.begin(); it != waiting.end(); it++) {
                if (it->getName() == name) {
                    waiting.erase(it);
                    return true;
                }
            }
            return false;
        }
    public:
        Trampoline() {
        }
        void arrive(std::string name, int age) {
            waiting.push_front(Kid(name, age));
        }
        void enter() {
            if (waiting.size() > 0) {
                playing.push_front(waiting.back());
                waiting.pop_back();
            }
        }
        void leave() {
            if (playing.size() > 0) {
                waiting.push_front(playing.back());
                playing.pop_back();
            }
        }
        void removeKid(std::string name) {
            bool removedFromPlaying = removeFromList(name, playing);
            bool removedFromWaiting = removeFromList(name, waiting);

            if (!removedFromPlaying && !removedFromWaiting) {
                std::cout << "fail: " << name << " nao esta no pula-pula" << std::endl;
            }
        }

        std::string show() {
            std::string out = "[";
            out += map_join(waiting, [](Kid k) { return k.toString(); }, ", ");
            out += "] => [";
            out += map_join(playing, [](Kid k) { return k.toString(); }, ", ");
            out += "]";
            return out;
        }

};



int main() {
    Trampoline trampoline;
    while (true) {
        std::string line, cmd;
        getline(std::cin, line);
        std::cout << "$" << line << std::endl;

        std::stringstream ss(line);
        ss >> cmd;

        if (cmd == "end") {
            break;
        } else if (cmd == "show") {
            std::cout << trampoline.show() << std::endl;
        } else if (cmd == "arrive") {
            std::string name;
            int age;
            ss >> name >> age;
            trampoline.arrive(name, age);
        } else if (cmd == "enter") {
            trampoline.enter();
        } else if (cmd == "leave") {
            trampoline.leave();
        } else if (cmd == "remove") {
            std::string name;
            ss >> name;
            trampoline.removeKid(name);
        } else {
            std::cout << "fail: comando invalido" << std::endl;
        }
    }
}
