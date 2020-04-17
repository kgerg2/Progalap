#pragma once
#include "card.h"
#include <vector>

class Account {
private:
    int balance;
    std::string accountNo;
    std::vector<Card *> cards;

public:
    Account(const std::string &no) : accountNo(no), balance(0) {}
    int getBalance() const { return balance; }
    void add(int a) { balance += a; }
    void addCard(Card *c) { cards.push_back(c); }
    bool hasCard(const std::string &cardNo) const;
};