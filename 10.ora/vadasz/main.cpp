#include "vadasz.cpp"
#include <iostream>

int main() {
    Vadasz v("Bivaly Bela", 42);
    v.ujTrofea(new OroszlanTrofea("Afrika", "2000-05-23", 127, nosteny));
    v.ujTrofea(new OrrszarvuTrofea("Afrika", "2000-05-27", 730, 17));
    v.ujTrofea(new OroszlanTrofea("Afrika", "2003-06-10", 120, him));
    v.ujTrofea(new ElefantTrofea("Afrika", "2003-06-13", 1010, 12, 13));
    v.ujTrofea(new OroszlanTrofea("Afrika", "2003-06-20", 170, him));

    std::cout << v.himOroszlanDb() << " db him oroszlant ejtett el" << std::endl;
    return 0;
}