#include "sugarzas.h"
#include "noveny.h"

std::shared_ptr<Alfa> Alfa::_peldany = nullptr;
std::shared_ptr<Alfa> Alfa::peldany()
{
    if(_peldany == nullptr) {
        _peldany = std::make_shared<Alfa>();
    }
    return _peldany;
}

bool Alfa::hat(Parabokor *p) {
    p->tapanyagNovel(1);
    return p->el();
}

bool Alfa::hat(Puffancs *p) {
    p->tapanyagNovel(2);
    return p->el();
}

bool Alfa::hat(Deltafa *d) {
    d->tapanyagNovel(-3);
    return d->el();
}

std::shared_ptr<Delta> Delta::_peldany = nullptr;
std::shared_ptr<Delta> Delta::peldany()
{
    if(_peldany == nullptr) {
        _peldany = std::make_shared<Delta>();
    }
    return _peldany;
}


bool Delta::hat(Parabokor *p) {
    p->tapanyagNovel(1);
    return p->el();
}

bool Delta::hat(Puffancs *p) {
    p->tapanyagNovel(-2);
    return p->el();
}

bool Delta::hat(Deltafa *d) {
    d->tapanyagNovel(4);
    return d->el();
}

std::shared_ptr<Nincs> Nincs::_peldany = nullptr;
std::shared_ptr<Nincs> Nincs::peldany()
{
    if(_peldany == nullptr) {
        _peldany = std::make_shared<Nincs>();
    }
    return _peldany;
}


bool Nincs::hat(Parabokor *p) {
    p->tapanyagNovel(-1);
    return p->el();
}

bool Nincs::hat(Puffancs *p) {
    p->tapanyagNovel(-1);
    return p->el();
}

bool Nincs::hat(Deltafa *d) {
    d->tapanyagNovel(-1);
    return d->el();
}