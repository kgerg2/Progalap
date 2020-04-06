#pragma once

#include <string>
#include <fstream>

enum Status { abnorm, norm };

struct Trofea {
    std::string nev;
    std::string fajta;
    int suly;
};

class Enor
{
    public:
        enum Errors { FILEERROR };
        Enor(const std::string &str);
        void first() { read(); next(); }
        void next();
        bool current() const { return _akt; }
        bool end() const { return _vege; }
    private:
        std::ifstream _x;
        Trofea _dx;
        Status _sx;
        bool _akt;
        bool _vege;

        void read();
};


