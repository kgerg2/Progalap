#include "recipeEnor.h"
#include <string>

RecipeEnor::RecipeEnor(const std::string &f) : x(f) {
    if (x.fail())
        throw FileException;
}

void RecipeEnor::read() {
    st = x >> dx ? norm : abnorm;
    std::string temp;
    getline(x, temp);
}

void RecipeEnor::next() {
    _end = st == abnorm;
    if (!_end) {
        _curr.count = 0;
        _curr.name = dx;
        for (; st == norm && _curr.name == dx; read()) {
            _curr.count++;
        }
    }
}