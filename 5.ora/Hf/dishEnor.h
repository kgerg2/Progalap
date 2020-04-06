#pragma once

#include <fstream>

struct Dish
{
    std::string name;
    int count;
    int price;
};

enum Status
{
    norm,
    abnorm
};

class dishEnor
{
private:
    std::ifstream f;
    Status st;
    Dish dx;
    Dish _curr;
    bool _end;

    void read(std::ifstream &f, Status &st, Dish &dx);

public:
    enum Errors { FileError };

    dishEnor(const std::string &_f);
    void first() { read(f, st, dx); next(); }
    void next();
    Dish current() { return _curr; }
    bool end() { return _end; }
};