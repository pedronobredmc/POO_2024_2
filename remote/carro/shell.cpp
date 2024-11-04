#include "fn.hpp"
#include "student.cpp"

int main() {
    if(Debug::debug) {
        Debug::run();
        return 0;
    }
    car c;
    c.construct_car(0, 2, 0, 100, 0);

    
    while (true) {
    std::string line = input();
    write("$" + line);
    std::vector<std::string> args;
     args = split(line, ' ');

    if (args[0] == "end") {
        break;
    }else if (args[0] == "show") {
        write(c.show());
    }else if (args[0] == "enter") {
        c.enter();
    }else if (args[0] == "fuel") {
        c.fuel(+args[1]);
    }else if (args[0] == "leave") {
        c.leave();
    }else if (args[0] == "drive") {
        c.drive(+args[1]);
    }
    }
}
