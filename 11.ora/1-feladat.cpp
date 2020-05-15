#include "../library/linsearch.hpp"
#include "../library/seqinfileenumerator.hpp"
#include "../library/summation.hpp"

using namespace std;

class EvenSearch : public LinSearch<int> {
protected:
    bool cond(const int &e) const override { return e % 2 == 0; }
};

class SumOdd : public Summation<int> {
protected:
    void first() override {}
    int neutral() const override { return 0; }
    int func(const int &e) const override { return e; }
    int add(const int &a, const int &b) const override { return a + b; }
    bool cond(const int &e) const override { return e % 2 == 1; }
};

int main(int argc, char const *argv[]) {
    string file = argc > 1 ? argv[1] : "11.ora\\in1.txt";
    SeqInFileEnumerator<int> in(file);
    EvenSearch ls;
    ls.addEnumerator(&in);
    ls.run();
    SumOdd so;
    so.addEnumerator(&in);
    so.run();
    cout << so.result() << endl;
    return 0;
}
