#include <iostream>
#include "vadaszenor.hpp"

int main() {
    VadaszEnor t("inp.txt");
    
    int c = 0;
    t.first();
    while (!t.end()) {
        Vadasz v = t.current();
        if (v.nyul && v.osszsuly > 250) {
            ++c;
        }
        t.next();
    }
    
    std::cout << c << " ilyen vadasz volt." << std::endl;
    return 0;
}
