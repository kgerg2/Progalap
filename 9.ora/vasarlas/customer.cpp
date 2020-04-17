#include "customer.h"

bool Customer::linSearch(std::string name, Department *r, Product *&pr) const {
    bool l = false;
    for (Product *p : r->stock) {
        if (l = (name == p->name)) {
            pr = p;
            break;
        }
    }
    return l;
}