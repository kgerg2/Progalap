#include "../library/seqinfileenumerator.hpp"
#include "../library/intervalenumerator.hpp"
#include "../library/linsearch.hpp"
#include "../library/summation.hpp"
#include <string>

using namespace std;

class SearchDivisor : public LinSearch<int> {
private:
    int num;
public:
    SearchDivisor(int e) : num(e) {}
protected:
    bool cond(const int &e) const override { return num % e == 0; }
};

class FilterPrimes : public Summation<int, ostream> {
public:
    FilterPrimes(ostream *o) : Summation(o) {}
protected:
    string func(const int &e) const override { return to_string(e) + " ";}
    bool cond(const int &e) const override {
        if (e == 1) return false;
        SearchDivisor sd(e);
        IntervalEnumerator enor(2, e/2);
        sd.addEnumerator(&enor);
        sd.run();
        return !sd.found();
    }
};

int main(int argc, char const *argv[])
{
    string file = argc > 1 ? argv[1] : "./11.ora/input.txt";
    ofstream o("./11.ora/output.txt");
    FilterPrimes f(&o);
    SeqInFileEnumerator<int> enor(file);
    f.addEnumerator(&enor);
    f.run();
    return 0;
}
