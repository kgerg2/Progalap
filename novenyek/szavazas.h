#pragma once

#include "sugarzas.h"

class Szavazas {
private:
    int _alfa;
    int _delta;

public:
    Szavazas():_alfa(0), _delta(0) {}
    void szavaz(const std::shared_ptr<Alfa> &a, int db) { _alfa += db; };
    void szavaz(const std::shared_ptr<Delta> &d, int db) { _delta += db; };
    std::shared_ptr<Sugarzas> eredmeny() const;
};