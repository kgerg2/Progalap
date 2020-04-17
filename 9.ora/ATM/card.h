#include <string>

class Card {
private:
    std::string pinCode;

public:
    std::string cardNo;
    std::string bankCode;
    bool pinCheck(const std::string &p) { return pinCode == p; }
};