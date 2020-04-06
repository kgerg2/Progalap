#include <iostream>
#include <sstream>
#include <string>

enum Status {
    norm, abnorm
};

template <class T>
void read(std::istream &f, T &df, Status &st) {
    std::string line;
    std::getline(f, line);
    st = f.fail() ? abnorm : norm;
    
    if (st == norm) {
        std::istringstream is(line);
        is >> df;
    }
}