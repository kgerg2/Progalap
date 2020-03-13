//Készítette:    Veszprémi Anna
//Dátum:         2019.02.19.
//Prioritásos sor forrás kódja

#include "priorsor.h"

using namespace std;

// TODO: PrQueue metódusainak implementálása

int PrQueue::maxindex() const {
    if (isEmpty())
    {
        throw PrQueue::EMPTY_PRQUEUE;
    }
    
    int ind = 0, mx = _vec[0].pr;
    for (int i = 0; i < _vec.size(); i++)
    {
        if (_vec[i].pr > mx)
        {
            mx = _vec[i].pr;
            ind = i;
        }
    }
    return ind;
}

void PrQueue::add(const Item& e) {
    _vec.push_back(e);
}

Item PrQueue::remMax() {
    int i = maxindex();
    Item e = _vec[i];
    _vec.erase(_vec.begin() + i);
    return e;
}

Item PrQueue::max() {
    return _vec[maxindex()];
}

ostream& operator<<(std::ostream& s, const PrQueue_Test& q)
{
    s<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    s<<"PrQueue jellemzoi:\n";
    s<<"_vec hossza:"<<q._vec.capacity()<<" Elemszam:"<<q._vec.size()<<"\nTartalma: "<<endl;
    for(unsigned i=0; i<q._vec.size(); ++i){
        s<<" ("<<q._vec[i].pr<<","<<q._vec[i].data<<")";
    }
    s<<"\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n";
    return s;
}

vector<Item>& PrQueue_Test::getItems() const
{
    return _vec;
}
