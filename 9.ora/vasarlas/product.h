#pragma once
#include <string>

class Product {
public:
    std::string name;
    int price;
    Product(std::string n, int a) : name(n), price(a) {}
};