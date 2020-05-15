#include "vadasz.h"

int Vadasz::himOroszlanDb() const {
    int db = 0;
    for (Trofea *trofea : _trofeak) {
        if (trofea->faj() == "oroszlan" && ((OroszlanTrofea*)trofea)->getNem() == him)
        {
            db++;
        }
    }
    return db;
}