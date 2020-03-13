//Készítette:    Veszprémi Anna
//Dátum:         2019.02.19.
//Prioritásos sor header állománya

#ifndef PRIORSOR_H_INCLUDED
#define PRIORSOR_H_INCLUDED
#include <string>
#include <iostream>
#include <vector>
#include "read.hpp"

//A prioritásos sor elemei egy egészből (prioritás) és egy szövegből állnak
//Az elem típusát megvalósító struct

//segéd függvény az ellenőrzött beolvasáshoz.
//Többszörös deklaráció elkerülése miatt inline
inline bool valid(int a) { return true; }

struct Item
{
    //publikus adattagok
    int pr;
    std::string data;

    //Paraméter nélküli (üres)-, és paraméteres konstruktor
    Item(){};
    Item(int p, const std::string &s) : pr(p), data(s) {}

    //Az elem kényelmes beolvasása/kiírása céljából készíthetünk >> és << operátort
    friend std::istream &operator>>(std::istream &s, Item &e)
    {
        e.pr = read<int>("Elem prioritasa:", "Egesz szamot kerek!", valid);
        std::cout << "Elembe kerulo adat:";
        s >> e.data;
        return s;
    }
    friend std::ostream &operator<<(std::ostream &s, const Item &e)
    {
        s << "prioritas: " << e.pr << " adat: " << e.data << " ";
        return s;
    }

    //Teszteléshez készült, egyenlőséget vizsgáló == operátor
    bool operator==(const Item &b)
    {
        return (pr == b.pr && data == b.data);
    }
};

//A prioritásos sor felülete
class PrQueue
{
public:
    enum PrQueueError
    {
        EMPTY_PRQUEUE
    };

    bool isEmpty() const { return !_vec.size(); }

    void add(const Item& e);

    Item remMax();

    Item max();

    friend std::ostream &operator<<(std::ostream &s, const PrQueue &q);
    // TODO: metódusok hozzáadása

private:
    std::vector<Item> _vec;

    int maxindex() const; // TODO: maxindex implementálása
};

class PrQueue_Test : public PrQueue
{
public:
    //Csak a teszteléshez használatos metódusok
    friend std::ostream &operator<<(std::ostream &s, const PrQueue_Test &q); //sor kiirása
    unsigned int getLength() const { return _vec.size(); }
    unsigned int getCapacity() const { return _vec.capacity(); }
    std::vector<Item> &getItems() const;
    int getMaxindex() const { return maxindex(); } //maxindex privát, nem hívható meg kívülről
};

#endif // PRIORSOR_H_INCLUDED
