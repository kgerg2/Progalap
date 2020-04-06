#include "dishEnor.h"

dishEnor::dishEnor(const std::string &_f) : f(_f)
{
    if (f.fail())
    {
        throw FileError;
    }
}

void dishEnor::read(std::ifstream &f, Status &st, Dish &dx)
{
    std::string tmp;
    st = f >> tmp >> dx.name >> tmp >> dx.count >> dx.price ? norm : abnorm;
}

void dishEnor::next()
{
    _end = st == abnorm;
    if (!_end)
    {
        _curr.name = dx.name;
        _curr.price = dx.price;
        _curr.count = 0;
        for (; st == norm && _curr.name == dx.name; read(f, st, dx))
        {
            _curr.count += dx.count;
        }
    }
}