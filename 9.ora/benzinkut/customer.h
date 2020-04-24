#pragma once

#include "gasStation.h"

class Customer {
    int money;

public:
    Customer(int m) : money(m) {}
    void tank(GasStation *g, int dispenserNumber, int amount);
    int getMoney() { return money; }
};

void Customer::tank(GasStation *g, int dispenserNumber, int amount) {
    g->getDispenser(dispenserNumber)->fill(amount);
    money -= g->getCashRegister()->pay(dispenserNumber);
}
