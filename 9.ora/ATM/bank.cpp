#include "bank.h"

int Bank::getBalance(std::string cardNo) const {
    Account *acc = search(cardNo);
    if (acc != nullptr) {
        return acc->getBalance();
    } else {
        return -1;
    }
}

void Bank::transaction(std::string cardNo, int a) {
    Account *acc = search(cardNo);
    if (acc != nullptr)
        acc->add(a);
}

Account* Bank::search(std::string cardNo) const {
    for (Account* acc : accounts) {
        if (acc->hasCard(cardNo))
            return acc;
    }
    return nullptr;
}