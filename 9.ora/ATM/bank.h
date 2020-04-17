#pragma once
#include "account.h"

class Bank {
private:
    std::vector<Account *> accounts;
    Account *search(std::string cardNo) const;

public:
    std::string bankCode;
    int getBalance(std::string cardNo) const;
    void transaction(std::string cardNo, int a);
};