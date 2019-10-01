#include <iostream>

using namespace std;

const string Napok[] = {"hetfo", "kedd", "szerda", "csutortok", "pentek", "szombat", "vasarnap"};

bool Helyes(string nap){
    int i=0;
    bool helyes;
    while(i < 7 && Napok[i] != nap){
        i++;
    }
    helyes = !(i >= 7);
    if(!helyes) cerr << "Hiba: nem nap" << endl;
    return helyes;
}

bool HelyesN(int h){
    if(h <= 0) cerr << "Hiba: nem pozitiv" << endl;
    return h > 0;
}

int main(){
    string kezd, mikor;
    int hossz, i, vegindex;

    do{
        cerr << "Tabor kezdete: ";
        cin >> kezd;
    } while(!Helyes(kezd));

    do{
        cerr << "Tabor hossza: ";
        cin >> hossz;
    } while(!HelyesN(hossz));

    i = 0;
    while(Napok[i] != kezd){
        i++;
    }
    vegindex = (i+hossz)%7;
    mikor = Napok[vegindex];
    cout << mikor << endl;
    return 0;
}
