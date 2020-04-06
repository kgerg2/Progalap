#include "enor.h"
#include <ios>
#include <sstream>

std::ostream &operator<<(std::ostream &out, Szo &s) {
    return out << s.szo;
}

std::istream &operator>>(std::istream &in, Szo &s) {
    in >> s.szo;
    s.w = s.szo.find('w');
    return in;
}

Enor::Enor(const std::string &file) : f(file) {
    std::noskipws(f);
    if (f.fail()) {
        throw FILE_ERROR;
    }
}

void Enor::read() {
    sx = f >> dx ? norm : abnorm;
}

void Enor::next() {
    bool l = false;
    while (sx == norm && dx == ' ') {
        read();
    }
    _end = sx == abnorm;
    if (!_end) {
        std::ostringstream os;
        _curr.w = false;
        while (sx == norm && dx != ' ')
        {
            os << dx;
            _curr.w |= dx == 'w';
            read();
        }
        _curr.szo = os.str();
    }
}