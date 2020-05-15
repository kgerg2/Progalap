#include "noveny.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void kiir(int nap, const string &sugarzas, const vector<shared_ptr<Noveny>> &v) {
    cout << nap << ". nap" << endl;
    cout << "Sugarzas: " << sugarzas << endl;
    for (shared_ptr<Noveny> e : v) {
        cout << e << endl;
    }
    cout << endl;
}

void beolvas(const string &fajl, vector<shared_ptr<Noveny>> &novenyek, int &idotartam) {
    ifstream f(fajl);
    if (f.fail()) {
        cout << "A fajl megnyitasa sikertelen." << endl;
        return;
    }
    int db, tapanyag;
    string nev;
    char faj;
    f >> db;
    novenyek.resize(db);
    for (int i = 0; i < db; i++) {
        f >> nev >> faj >> tapanyag;
        switch (faj) {
        case 'p':
            novenyek[i] = make_shared<Puffancs>(nev, tapanyag);
            break;
        case 'b':
            novenyek[i] = make_shared<Parabokor>(nev, tapanyag);
            break;
        case 'd':
            novenyek[i] = make_shared<Deltafa>(nev, tapanyag);
            break;
        }
    }
    f >> idotartam;
}

shared_ptr<Sugarzas> nap(vector<shared_ptr<Noveny>> &novenyek, const shared_ptr<Sugarzas> &s) {
    shared_ptr<Szavazas> szavazas = make_shared<Szavazas>();
    for (shared_ptr<Noveny> noveny : novenyek) {
        if (noveny->el() && noveny->reagal(s)) {
            noveny->szavaz(szavazas);
        }
    }
    return szavazas->eredmeny();
}

void szimulal(vector<shared_ptr<Noveny>> &novenyek, int idotartam) {
    shared_ptr<Sugarzas> elozo = nullptr, sugarzas = Nincs::peldany();
    bool felt = false;
    cout << "Bemenet - ";
    for (int i = 0; i <= idotartam && !felt; i++) {
        kiir(i, sugarzas->nev(), novenyek);
        felt = elozo == Nincs::peldany() && sugarzas == Nincs::peldany();
        elozo = sugarzas;
        sugarzas = nap(novenyek, sugarzas);
    }
}

#define NORMAL_MODE
#ifdef NORMAL_MODE

int main() {
    int idotartam;
    vector<shared_ptr<Noveny>> novenyek;
    beolvas("in10.txt", novenyek, idotartam);
    szimulal(novenyek, idotartam);
    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <sstream>

// növények száma

TEST_CASE("ures fajl", "in1.txt") {
    int idotartam;
    vector<shared_ptr<Noveny>> novenyek;

    beolvas("in1.txt", novenyek, idotartam);

    CHECK(novenyek.size() == 0);
    CHECK(idotartam == 0);

    stringstream ss;
    cout.rdbuf(ss.rdbuf());

    szimulal(novenyek, idotartam);

    CHECK(ss.str() == "Bemenet - 0. nap\nSugarzas: nincs\n\n");
}

TEST_CASE("egy noveny", "in2.txt") {
    int idotartam;
    vector<shared_ptr<Noveny>> novenyek;

    beolvas("in2.txt", novenyek, idotartam);

    CHECK(novenyek.size() == 1);
    CHECK(idotartam == 1);

    stringstream ss;
    cout.rdbuf(ss.rdbuf());

    szimulal(novenyek, idotartam);

    CHECK(ss.str().find("Egyke (parabokor 8 tapanyaggal)\n") != string::npos);
    CHECK(ss.str().find("Egyke (parabokor 7 tapanyaggal)\n") != string::npos);
}

TEST_CASE("tobb noveny", "in3.txt") {
    int idotartam;
    vector<shared_ptr<Noveny>> novenyek;

    beolvas("in3.txt", novenyek, idotartam);

    CHECK(novenyek.size() == 3);
    CHECK(idotartam == 1);

    stringstream ss;
    cout.rdbuf(ss.rdbuf());

    szimulal(novenyek, idotartam);

    CHECK(ss.str().find("puffancs 7 tapanyaggal") != string::npos);
    CHECK(ss.str().find("deltafa 5 tapanyaggal") != string::npos);
    CHECK(ss.str().find("parabokor 4 tapanyaggal") != string::npos);

    CHECK(ss.str().find("puffancs 6 tapanyaggal") != string::npos);
    CHECK(ss.str().find("deltafa 4 tapanyaggal") != string::npos);
    CHECK(ss.str().find("parabokor 3 tapanyaggal") != string::npos);
}

// növények tulajdonságai

TEST_CASE("halott novenyek", "in4.txt") {
    int idotartam;
    vector<shared_ptr<Noveny>> novenyek;

    beolvas("in4.txt", novenyek, idotartam);

    CHECK(novenyek.size() == 3);
    CHECK(idotartam == 1);

    stringstream ss;
    cout.rdbuf(ss.rdbuf());

    szimulal(novenyek, idotartam);

    CHECK(ss.str().find("0 tapanyaggal - nem el") != string::npos);
    CHECK(ss.str().find("-3 tapanyaggal - nem el") != string::npos);
    CHECK(ss.str().find("19 tapanyaggal - nem el") != string::npos);

    CHECK(ss.str().find("1. nap\nSugarzas: nincs") != string::npos);
}

TEST_CASE("egy noveny, van sugarzas", "in5.txt") {
    int idotartam;
    vector<shared_ptr<Noveny>> novenyek;

    beolvas("in5.txt", novenyek, idotartam);

    CHECK(novenyek.size() == 1);
    CHECK(idotartam == 1);

    stringstream ss;
    cout.rdbuf(ss.rdbuf());

    szimulal(novenyek, idotartam);
    
    CHECK(ss.str().find("1. nap\nSugarzas: delta") != string::npos);
}

TEST_CASE("tobb noveny, nincs sugarzas", "in6.txt") {
    int idotartam;
    vector<shared_ptr<Noveny>> novenyek;

    beolvas("in6.txt", novenyek, idotartam);

    CHECK(novenyek.size() == 4);
    CHECK(idotartam == 1);

    stringstream ss;
    cout.rdbuf(ss.rdbuf());

    szimulal(novenyek, idotartam);

    CHECK(ss.str().find("1. nap\nSugarzas: nincs") != string::npos);
}

// napok száma

TEST_CASE("0 nap szimulacioja", "in7.txt") {
    int idotartam;
    vector<shared_ptr<Noveny>> novenyek;

    beolvas("in7.txt", novenyek, idotartam);

    CHECK(novenyek.size() == 1);
    CHECK(idotartam == 0);

    stringstream ss;
    cout.rdbuf(ss.rdbuf());

    szimulal(novenyek, idotartam);

    CHECK(ss.str() == "Bemenet - 0. nap\nSugarzas: nincs\nEgyke (parabokor 8 tapanyaggal)\n\n");
}

TEST_CASE("1 nap szimulacioja", "in3.txt") {
    int idotartam;
    vector<shared_ptr<Noveny>> novenyek;

    beolvas("in3.txt", novenyek, idotartam);

    CHECK(novenyek.size() == 3);
    CHECK(idotartam == 1);

    stringstream ss;
    cout.rdbuf(ss.rdbuf());

    szimulal(novenyek, idotartam);

    CHECK(ss.str().find("puffancs 7 tapanyaggal") != string::npos);
    CHECK(ss.str().find("deltafa 5 tapanyaggal") != string::npos);
    CHECK(ss.str().find("parabokor 4 tapanyaggal") != string::npos);

    CHECK(ss.str().find("1. nap") != string::npos);
    CHECK(ss.str().find("puffancs 6 tapanyaggal") != string::npos);
    CHECK(ss.str().find("deltafa 4 tapanyaggal") != string::npos);
    CHECK(ss.str().find("parabokor 3 tapanyaggal") != string::npos);

    CHECK_FALSE(ss.str().find("2. nap") != string::npos);
    
}

TEST_CASE("tobb nap szimulacioja", "in8.txt") {
    int idotartam;
    vector<shared_ptr<Noveny>> novenyek;

    beolvas("in8.txt", novenyek, idotartam);

    CHECK(novenyek.size() == 1);
    CHECK(idotartam == 3);

    stringstream ss;
    cout.rdbuf(ss.rdbuf());

    szimulal(novenyek, idotartam);
    
    CHECK(ss.str().find("1. nap\nSugarzas: delta") != string::npos);
    CHECK(ss.str().find("2. nap\nSugarzas: nincs") != string::npos);
    CHECK(ss.str().find("3. nap\nSugarzas: delta") != string::npos);
}

// feltétel - sugárzásmentesség

TEST_CASE("rogton sugarzasmentes", "in9.txt") {
    int idotartam;
    vector<shared_ptr<Noveny>> novenyek;

    beolvas("in9.txt", novenyek, idotartam);

    CHECK(novenyek.size() == 4);
    CHECK(idotartam == 10);

    stringstream ss;
    cout.rdbuf(ss.rdbuf());

    szimulal(novenyek, idotartam);

    CHECK(ss.str().find("1. nap\nSugarzas: nincs") != string::npos);

    CHECK_FALSE(ss.str().find("2. nap") != string::npos);
}

TEST_CASE("tobb nap, tobb noveny szimulacioja", "in10.txt") {
    int idotartam;
    vector<shared_ptr<Noveny>> novenyek;

    beolvas("in10.txt", novenyek, idotartam);

    CHECK(novenyek.size() == 3);
    CHECK(idotartam == 3);

    stringstream ss;
    cout.rdbuf(ss.rdbuf());

    szimulal(novenyek, idotartam);

    CHECK(ss.str().find("puffancs 7 tapanyaggal") != string::npos);
    CHECK(ss.str().find("deltafa 5 tapanyaggal") != string::npos);
    CHECK(ss.str().find("parabokor 4 tapanyaggal") != string::npos);

    CHECK(ss.str().find("1. nap") != string::npos);
    CHECK(ss.str().find("puffancs 6 tapanyaggal") != string::npos);
    CHECK(ss.str().find("deltafa 4 tapanyaggal") != string::npos);
    CHECK(ss.str().find("parabokor 3 tapanyaggal") != string::npos);

    CHECK(ss.str().find("2. nap") != string::npos);
    CHECK(ss.str().find("puffancs 8 tapanyaggal") != string::npos);
    CHECK(ss.str().find("deltafa 1 tapanyaggal") != string::npos);
    CHECK(ss.str().find("parabokor 4 tapanyaggal") != string::npos);

    CHECK(ss.str().find("3. nap") != string::npos);
    CHECK(ss.str().find("puffancs 10 tapanyaggal") != string::npos);
    CHECK(ss.str().find("deltafa -2 tapanyaggal - nem el") != string::npos);
    CHECK(ss.str().find("parabokor 5 tapanyaggal") != string::npos);
}

#endif