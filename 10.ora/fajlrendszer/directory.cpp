#include "directory.h"

int Directory::getSize() const {
    int s = 0;
    for (Record *rec : records) {
        s += rec->getSize();
    }
    return s;
}