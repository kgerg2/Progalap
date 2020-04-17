#include "department.h"
#include <fstream>

void Department::takeOutFromStock(Product *p) {
    bool l = false;
    int ind;
    for (int i = 0; i < stock.size() && !l; i++) {
        l = stock[i]->name == p->name;
        if (l)
            ind = i;
    }
    if (l)
        stock.erase(stock.begin() + ind);
}