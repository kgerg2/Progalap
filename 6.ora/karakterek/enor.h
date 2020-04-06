#include <fstream>

struct Szo {
    std::string szo;
    bool w;
};

enum Status
{
    norm,
    abnorm
};

class Enor
{
private:
    std::ifstream f;
    Status sx;
    char dx;
    Szo _curr;
    bool _end;

    void read();

public:
    enum Error { FILE_ERROR };
    Enor(const std::string &file);
    void first() { read(); next(); }
    void next();
    Szo current() const { return _curr; }
    bool end() const { return _end; }
};

std::ostream &operator<<(std::ostream &out, Szo &s);
std::istream &operator>>(std::istream &in, Szo &s);