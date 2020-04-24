#pragma once

#include "cashDesk.h"

class GasStation;

class CashRegister {
private:
    GasStation *gasStation;
    CashDesk *desk1, *desk2;

public:
    CashRegister(GasStation *station) : gasStation(station) {}
    int pay(int dispenserNum);
};