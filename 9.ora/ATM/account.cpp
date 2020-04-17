#include "account.h"

bool Account::hasCard(const std::string &cardNo) const {
    for (Card *c : cards) {
        if (c->cardNo == cardNo)
            return true;
    }
    return false;
}