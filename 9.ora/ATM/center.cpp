#include "center.h"

void Center::transaction(const std::string &code, const std::string &cardNo, int a) {
    Bank *bank = search(cardNo);
    if (bank != nullptr)
        bank->transaction(cardNo, a);
}

int Center::getBalance(const std::string &code, const std::string &cardNo) const {
    Bank *bank = search(cardNo);
    if (bank != nullptr)
        return bank->getBalance(cardNo);
}

Bank *Center::search(const std::string &code) const {
    for (Bank *b : banks) {
        if (b->bankCode == code)
            return b;
    }
    return nullptr;
}