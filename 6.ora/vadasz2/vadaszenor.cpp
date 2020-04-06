#include "vadaszenor.hpp"

void VadaszEnor::next() {
    vege = y.end();
    
    if (!vege) {
        akt.nev = y.current().nev;
        akt.nyul = true;
        akt.osszsuly = 0;
        while(!y.end() && y.current().nev == akt.nev) {
            akt.nyul = akt.nyul && y.current().lott;
            akt.osszsuly += y.current().ossz;
            y.next();
        }
    }
}
