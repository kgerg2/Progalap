#pragma once
#include "store.h"

class Customer {
public:
    std::string name;
    std::vector<std::string> list;
    std::vector<Product *> cart;

    bool linSearch(std::string name, Department *r, Product *&pr) const;
};
