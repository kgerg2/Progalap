#pragma once
#include "product.h"
#include <vector>

class Department {
public:
    Department(/* args */);
    void takeOutFromStock(Product *p);
    std::vector<Product *> stock;
};
