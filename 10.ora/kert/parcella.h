#pragma once

#include "noveny.h"

class Parcella {
private:
    int ultetesi_ido;
    int sorszam;
    Noveny *nov;

public:
    Parcella(int ssz) : sorszam(ssz) {}
    int getSorszam() const { return sorszam; }
    int getUltetesiIdo() const { return ultetesi_ido; }
    Noveny *getNoveny() const { return nov; }
    void ultet(Noveny *n, int ido) {
        this->nov = n;
        this->ultetesi_ido = ido;
    }
};