#pragma once
#include "bank.h"

class Center {
private:
    std::vector<Bank *> banks;
    Bank *search(const std::string &code) const;

public:
    Center(/* args */);
    int getBalance(const std::string &code, const std::string &cardNo) const;
    void transaction(const std::string &code, const std::string &cardNo, int a);
};
