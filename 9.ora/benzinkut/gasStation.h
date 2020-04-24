#pragma once

#include "cashRegister.h"
#include "dispenser.h"
#include <vector>

class GasStation {
private:
    CashRegister cashRegister;
    std::vector<Dispenser> dispensers;
    int pricepl;

public:
    GasStation(int ppl) : pricepl(ppl), cashRegister(this), dispensers(6) {}
    int getPrice() { return pricepl; }
    Dispenser *getDispenser(int n) { if (n >= 0 && n < 6) return &dispensers[n]; }
    CashRegister *getCashRegister() { return &cashRegister; }
};

int CashRegister::pay(int dispenserNum) {
    int res = gasStation->getPrice() * gasStation->getDispenser(dispenserNum)->getScreenContent();
    gasStation->getDispenser(dispenserNum)->setScreenContent();
    return res;
}