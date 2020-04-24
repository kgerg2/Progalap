#include <iostream>
#include "customer.h"

int main() {
    Customer customer(10000);
    GasStation gasStation(300);

    customer.tank(&gasStation, 2, 15);
    std::cout << customer.getMoney() << " Ft is left" << std::endl;
    return 0;
}