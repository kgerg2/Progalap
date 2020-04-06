#include <iostream>
#include "enor.h"

using namespace std;

int main() {
    Enor t("inp.txt");
    bool l = false;
    Szo szo;
    
    for(t.first(); !t.end(); t.next()) {
        if (t.current().w) {
            if (l) {
                if (szo.szo.size() < t.current().szo.size()) {
                    szo = t.current();
                }
            } else {
                l = true;
                szo = t.current();
            }
        }
    }

    if (l) {
        cout << "A leghosszabb ilyen szó: " << szo << endl;
    } else {
        cout << "Nincs ilyen szó." << endl;
    }
    return 0;
}