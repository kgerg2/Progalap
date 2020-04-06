#include "osszesitesenor.hpp"
#include <iostream>

std::istream &operator>>(std::istream &in, Trofea &t) {
    return in >> t.nev >> t.datum >> t.fajta >> t.suly;
}

OsszesitesEnor::OsszesitesEnor(const std::string &f) : x(f) {
    if (x.fail()) {
        throw FILE_ERROR;
    }
}

void OsszesitesEnor::next() {
    vege = sx == abnorm;
    
    if (!vege) {
        akt.nev = dx.nev;
        akt.datum = dx.datum;
        akt.lott = false;
        akt.ossz = 0;
        while(sx == norm && dx.nev == akt.nev && dx.datum == akt.datum) {
            akt.lott = akt.lott || dx.fajta == "nyul";
            akt.ossz += dx.suly;
            read();
        }
    }
}

void OsszesitesEnor::read() {
    sx = (x >> dx) ? norm : abnorm;
}
