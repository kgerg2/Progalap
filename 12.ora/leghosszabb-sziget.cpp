#include "../library/counting.hpp"
#include "../library/enumerator.hpp"
#include "../library/maxsearch.hpp"
#include "../library/selection.hpp"
#include "../library/seqinfileenumerator.hpp"
#include <iostream>

using namespace std;

struct Island {
    int length;
    int no;
};

class CrossingSee : public Selection<int> {
protected:
    bool cond(const int &e) const override { return e != 0; }
    void first() override {}
};

class IslandLength : public Counting<int> {
protected:
    bool whileCond(const int &e) const override { return e > 0; }
    void first() override {}
};

class IslandEnumerator : public Enumerator<Island> {
private:
    Island _island;
    bool _end;
    SeqInFileEnumerator<int> _f;

public:
    IslandEnumerator(const string &fname) : _f(fname) {}

protected:
    void first() override {
        _f.first();
        _island.no = 0;
        next();
    }
    void next();
    Island current() const override { return _island; }
    bool end() const override { return _end; }
};

void IslandEnumerator::next() {
    CrossingSee pr1;
    pr1.addEnumerator(&_f);
    pr1.run();
    if (_end = _f.end())
        return;
    _island.no++;
    IslandLength pr2;
    pr2.addEnumerator(&_f);
    pr2.run();
    _island.length = pr2.result();
}

class MaxIsland : public MaxSearch<Island, int> {
protected:
    int func(const Island &e) const override { return e.length; }
};

int main(int argc, char const *argv[])
{
    string fname = argc == 1 ? "./12.ora/input.txt" : argv[1];
    MaxIsland mi;
    SeqInFileEnumerator<Island> f(fname);
    mi.addEnumerator(&f);
    mi.run();
    return 0;
}
