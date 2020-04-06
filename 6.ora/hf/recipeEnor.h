#pragma once
#include <fstream>

enum Status {
    norm,
    abnorm
};

struct Recipe {
    std::string name;
    int count;
};

class RecipeEnor {
private:
    std::ifstream x;
    Status st;
    std::string dx;
    Recipe _curr;
    bool _end;

    void read();

public:
    enum Exceptions { FileException };

    RecipeEnor(const std::string &f);
    void first() { read(); next(); }
    void next();
    Recipe current() { return _curr; }
    bool end() { return _end; }
};
