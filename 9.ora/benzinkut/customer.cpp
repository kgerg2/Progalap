#include "customer.h"

void Customer::tank(GasStation *g, int dispenserNumber, int amount) {
    g->getDispenser(dispenserNumber)->fill(amount);
    money -= g->getCashRegister()->pay(dispenserNumber);
}