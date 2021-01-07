#include <iostream>
#include "library/enumerator.hpp"
#include "library/maxsearch.hpp"
#include "library/seqinfileenumerator.hpp"
#include "library/stringstreamenumerator.hpp"
#include "library/summation.hpp"

using namespace std;

struct Test {
    string name;
    bool positive;

    friend istream &operator>>(istream &s, Test &t);
};

istream &operator>>(istream &s, Test &c) {
    s >> c.name;
    char temp;
    s >> temp;
    c.positive = temp == 'P';
    return s;
}

struct Statistics {
    int positive;
    int negative;
};

// Generate statistics for one patient
class SumTests : public Summation<Test, Statistics> {
protected:
    Statistics neutral() const override { return {0, 0}; }
    Statistics func(const Test &e) const override { return {e.positive, !e.positive}; }
    Statistics add(const Statistics &a, const Statistics &b) const override { return {a.positive + b.positive, a.negative + b.negative}; }
};

struct Patient {
    int TAJ;
    string hospital;
    Statistics stat;

    friend istream &operator>>(istream &s, Patient &p);
};

istream &operator>>(istream &s, Patient &p) {
    s >> p.TAJ >> p.hospital;
    string str;
    getline(s, str);
    stringstream ss(str);
    SumTests st;
    StringStreamEnumerator<Test> se(ss);
    st.addEnumerator(&se);
    st.run();
    p.stat = st.result();
    return s;
}

// Generate statistics for one hospital
class SumPatients : public Summation<Patient, Statistics> {
private:
    string _hospital;

protected:
    Statistics neutral() const override { return {0, 0}; }
    Statistics func(const Patient &e) const override { return e.stat; }
    Statistics add(const Statistics &a, const Statistics &b) const override { return {a.positive + b.positive, a.negative + b.negative}; }
    bool cond(const Patient &e) const override { return e.TAJ % 2 == 0; }
    bool whileCond(const Patient &e) const override { return e.hospital == _hospital; }
    void first() override {}

public:
    SumPatients(const string &hospital) : _hospital(hospital) {}
};

struct Hospital {
    string name;
    Statistics stat;
};

class HospitalEnumerator : public Enumerator<Hospital> {
private:
    SeqInFileEnumerator<Patient> _se;
    Hospital _e;
    bool _end;

public:
    HospitalEnumerator(const string &file) : _se(file), _end(false) {}
    void first() override {
        _se.first();
        next();
    }
    void next() override;
    Hospital current() const override { return _e; }
    bool end() const override { return _end; }
};

void HospitalEnumerator::next() {
    if (!(_end = _se.end())) {
        _e.name = _se.current().hospital;
        SumPatients sp(_e.name);
        sp.addEnumerator(&_se);
        sp.run();
        _e.stat = sp.result();
    }
}

// Search the hospital with the highest ratio
class MaxRatio : public MaxSearch<Hospital, double> {
protected:
    double func(const Hospital &e) const override { return (double)e.stat.positive / (e.stat.positive + e.stat.negative); }
    bool cond(const Hospital &e) const override { return e.stat.positive + e.stat.negative > 0; }
};


int main(int argc, char const *argv[]) {
    string file = argc > 1 ? argv[1] : "1.txt";
    try {
        HospitalEnumerator he(file);
        MaxRatio mr;
        mr.addEnumerator(&he);
        mr.run();

        if (mr.found()) {
            cout << mr.optElem().name << " is the hospital with the largest positive / tested ratio." << endl;
        } else {
            cout << "No hospitals tested patients with even TAJ numbers." << endl;
        }
    } catch (SeqInFileEnumerator<Patient>::Exceptions OPEN_ERROR) {
        cout << "File cannot be opened." << endl;
    }
    return 0;
}
