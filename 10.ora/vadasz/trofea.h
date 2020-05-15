#pragma once

#include <string>

class Trofea {
private:
    std::string _hely;
    std::string _datum;
    int _suly;

protected:
    Trofea(const std::string &hely, const std::string &datum, int suly) : _hely(hely), _datum(datum), _suly(suly) {}

public:
    virtual std::string faj() const = 0;
};

class ElefantTrofea : public Trofea {
private:
    int _agyar1Hossz;
    int _agyar2Hossz;

public:
    ElefantTrofea(const std::string &hely, const std::string &datum, int suly, int agyar1Hossz, int agyar2Hossz) : Trofea(hely, datum, suly), _agyar1Hossz(agyar1Hossz), _agyar2Hossz(agyar2Hossz) {}
    std::string faj() const override { return "elefant"; }
};

class OrrszarvuTrofea : public Trofea {
private:
    int _orrszarvSuly;

public:
    OrrszarvuTrofea(const std::string &hely, const std::string &datum, int suly, int orrszarvSuly) : Trofea(hely, datum, suly), _orrszarvSuly(orrszarvSuly) {}
    std::string faj() const override { return "orrszarvu"; }
};

enum Nem {
    him,
    nosteny
};

class OroszlanTrofea : public Trofea {
private:
    Nem _nem;

public:
    OroszlanTrofea(const std::string &hely, const std::string &datum, int suly, const Nem &nem) : Trofea(hely, datum, suly), _nem(nem) {}
    std::string faj() const override { return "oroszlan"; }
    Nem getNem() const { return _nem; }
};
