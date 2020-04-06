#ifndef OSSZESITESENOR_HPP_INCLUDED
#define OSSZESITESENOR_HPP_INCLUDED

#include <string>
#include <iostream>
#include <fstream>

struct Osszesites {
    std::string nev;
    std::string datum;
    bool lott;
    int ossz;
};

struct Trofea {
    std::string nev;
    std::string datum;
    std::string fajta;
    int suly;
};

std::istream &operator>>(std::istream &in, Trofea &t);

class OsszesitesEnor {
public:
    enum Error { FILE_ERROR };
    
    OsszesitesEnor(const std::string &f);
    
    void first() {
        read();
        next();
    }
    
    void next();
    
    Osszesites current() const {
        return akt;
    }
    
    bool end() const {
        return vege;
    }
    
private:
    enum Status { norm, abnorm };
    
    std::ifstream x;
    Trofea dx;
    Status sx;
    Osszesites akt;
    bool vege;
    
    void read();
};

#endif
