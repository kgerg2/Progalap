#pragma once

#include "trofea.h"
#include <vector>

class Vadasz {
private:
    std::string _nev;
    int _kor;
    std::vector<Trofea *> _trofeak;

public:
    Vadasz(const std::string nev, int kor) : _nev(nev), _kor(kor) {}
    int himOroszlanDb() const;
    void ujTrofea(Trofea *trofea) { _trofeak.push_back(trofea); }
};
