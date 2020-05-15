#include "szavazas.h"

std::shared_ptr<Sugarzas> Szavazas::eredmeny() const {
    if (_alfa - 3 >= _delta) {
        return Alfa::peldany();
    } else if (_delta - 3 >= _alfa) {
        return Delta::peldany();
    }
    return Nincs::peldany();
}