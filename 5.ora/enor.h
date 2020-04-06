#pragma once
#include <fstream>
#include <iostream>

struct Ugyfel
{
    std::string szaml;
    std::string datum;
    int ossz;
};

struct Egyenleg
{
    std::string szaml;
    int egy;
};

enum Status {
    norm, abnorm
};

class Enor
{
private:
    std::ifstream x;
    bool vege;
    Egyenleg akt;
    Status sx;
    Ugyfel dx;
public:
    enum Error {FILE_ERROR};

    Enor(const std::string &file);

    void first();
    void next();
    bool end() { return vege; }
    void read(std::istream &x, Status &sx, Ugyfel &dx);
};
