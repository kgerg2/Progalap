#ifndef VADASZENOR_HPP_INCLUDED
#define VADASZENOR_HPP_INCLUDED

#include <string>
#include "osszesitesenor.hpp"

struct Vadasz {
    std::string nev;
    bool nyul;
    int osszsuly;
};

class VadaszEnor {
public:
    VadaszEnor(const std::string &f) : y(f) {}
    
    void first() {
        y.first();
        next();
    }
    
    void next();
    
    Vadasz current() const {
        return akt;
    }
    
    bool end() const {
        return vege;
    }
    
private:
    OsszesitesEnor y;
    Vadasz akt;
    bool vege;
};

#endif
