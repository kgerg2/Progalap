#include "enor.h"

Enor::Enor(const std::string &file) : x(file) {
    if (x.fail())
    {
        throw FILE_ERROR;
    }
}

void Enor::next() {
    vege = sx == abnorm;
    if (!vege)
    {
        akt.szaml = dx.szaml;
        akt.egy = 0;
        for (; sx == norm && dx.szaml == akt.szaml; read(x, sx, dx))
        {
            akt.egy += dx.ossz;
        }
    }
}

std::istream &operator>>(std::istream &in, Ugyfel u) {
    return in >> u.szaml >> u.datum >> u.ossz;
}

void Enor::read(std::istream &x, Status &sx, Ugyfel &dx) {
    sx = (x >> dx) ? norm : abnorm;
}


std::ostream &operator<<(std::ostream &out, Egyenleg e) {
    return out << e.szaml << " " << e.egy;
}