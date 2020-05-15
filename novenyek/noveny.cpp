#include "noveny.h"

bool Puffancs::el() const {
    return _tapanyag > 0 && _tapanyag <= 10;
}

void Puffancs::szavaz(const std::shared_ptr<Szavazas> &sz) const {
    sz->szavaz(Alfa::peldany(), 10);
}

void Deltafa::szavaz(const std::shared_ptr<Szavazas> &sz) const {
    if (_tapanyag < 5) {
        sz->szavaz(Delta::peldany(), 4);
    } else if (_tapanyag <= 10) {
        sz->szavaz(Delta::peldany(), 1);
    }
}