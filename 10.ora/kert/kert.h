#pragma once

#include "parcella.h"
#include <vector>

class Kert {
private:
    std::vector<Parcella *> parcellak;

public:
    Kert(int n) : parcellak(n) {
        for (auto &&p : parcellak)
            p = new Parcella(p - parcellak.front());
    }
    Parcella *getParcella(int n) {
        return n >= 0 && n < parcellak.size() ? parcellak[n] : nullptr;
    }
    void ultet(int n, Noveny *nov, int ido) {
        if (n >= 0 && n < parcellak.size())
            parcellak[n]->ultet(nov, ido);
    }
};