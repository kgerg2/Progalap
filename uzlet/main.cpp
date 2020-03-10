#include <iostream>
#include <vector>
#include "read.hpp"

using namespace std;

struct termek {
    string nev;
    int ar = 0;
};

struct szamla {
    string vasarlo;
    int osszeg;
};

istream& operator>>(istream &f, struct termek &t) {
    return f >> t.nev >> t.ar;
}

istream& operator>>(istream &f, struct szamla &t) {
    f >> t.vasarlo;
    struct termek term;
    while(f >> term){
        t.osszeg += term.ar;
    }
    return f;
}

int main()
{
    string nev;
    struct szamla szaml;
    Status st;
    read(cin, szaml, st);
    if(st==norm) cout << szaml.osszeg << endl;
    cout << "Hello world!" << endl;
    return 0;
}
