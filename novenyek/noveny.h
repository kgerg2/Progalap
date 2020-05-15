#pragma once

#include "szavazas.h"
#include <ostream>
#include <string>

class Noveny {
protected:
    std::string _nev;
    int _tapanyag;

public:
    Noveny(const std::string &nev, int tapanyag) : _nev(nev), _tapanyag(tapanyag) {}
    void tapanyagNovel(int ertek) { _tapanyag += ertek; }
    virtual bool el() const { return _tapanyag > 0; }
    virtual bool reagal(const std::shared_ptr<Sugarzas> &s) = 0;
    virtual void szavaz(const std::shared_ptr<Szavazas> &sz) const {}
    virtual std::string faj() const = 0;
    friend std::ostream &operator<<(std::ostream &ki, const std::shared_ptr<Noveny> &n) { return ki << n->_nev << " (" << n->faj() << " " << n->_tapanyag << " tapanyaggal" << (n->el() ? ")" : " - nem el)"); };
};

class Parabokor : public Noveny {
public:
    Parabokor(const std::string &nev, int tapanyag) : Noveny(nev, tapanyag) {}
    std::string faj() const override { return "parabokor"; }
    virtual bool reagal(const std::shared_ptr<Sugarzas> &s) { return s->hat(this); }
};

class Puffancs : public Noveny {
public:
    Puffancs(const std::string &nev, int tapanyag) : Noveny(nev, tapanyag) {}
    bool el() const override;
    void szavaz(const std::shared_ptr<Szavazas> &sz) const override;
    std::string faj() const override { return "puffancs"; }
    virtual bool reagal(const std::shared_ptr<Sugarzas> &s) { return s->hat(this); }
};

class Deltafa : public Noveny {
public:
    Deltafa(const std::string &nev, int tapanyag) : Noveny(nev, tapanyag) {}
    void szavaz(const std::shared_ptr<Szavazas> &sz) const override;
    std::string faj() const override { return "deltafa"; }
    virtual bool reagal(const std::shared_ptr<Sugarzas> &s) { return s->hat(this); }
};
