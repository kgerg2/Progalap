#pragma once

#include <ostream>
#include <memory>

// std::ostream &operator<<(std::ostream &ki, const Sugarzas s);
class Parabokor;
class Puffancs;
class Deltafa;


class Sugarzas {
protected:
    Sugarzas() {}

public:
    virtual bool hat(Parabokor *p) = 0;
    virtual bool hat(Puffancs *p) = 0;
    virtual bool hat(Deltafa *d) = 0;
    virtual std::string nev() const = 0;
};

class Alfa : public Sugarzas {
private:
    static std::shared_ptr<Alfa> _peldany;

public:
    Alfa() {}
    static std::shared_ptr<Alfa> peldany();
    bool hat(Parabokor *p) override;
    bool hat(Puffancs *p) override;
    bool hat(Deltafa *d) override;
    std::string nev() const override { return "alfa"; }
};

class Delta : public Sugarzas {
private:
    static std::shared_ptr<Delta> _peldany;

public:
    Delta() {}
    static std::shared_ptr<Delta> peldany();
    bool hat(Parabokor *p) override;
    bool hat(Puffancs *p) override;
    bool hat(Deltafa *d) override;
    std::string nev() const override { return "delta"; }
};

class Nincs : public Sugarzas {
private:
    static std::shared_ptr<Nincs> _peldany;

public:
    Nincs() {}
    static std::shared_ptr<Nincs> peldany();
    bool hat(Parabokor *p) override;
    bool hat(Puffancs *p) override;
    bool hat(Deltafa *d) override;
    std::string nev() const override { return "nincs"; }
};
