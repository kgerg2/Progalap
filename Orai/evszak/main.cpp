#include <iostream>

using namespace std;

const string honapok[] = {"januar", "februar", "marcius", "aprilis", "majus", "junius", "julius", "augusztus", "szeptember", "oktober", "november", "december"};

bool Helyes(string honap){
    int i=0;
    bool helyes;
    while(i < 12 && honapok[i] != honap){
        i++;
    }
    helyes = i < 12;
    if(!helyes) cerr << "Hiba: nem honap" << endl;
    return helyes;
}


int main()
{
    const string evszakok[] = {"tel", "tavasz", "nyar", "osz"};
    string honap, evszak;
    int index, evszakindex;

    do{
        cerr << "Honap neve: ";
        cin >> honap;
    } while(!Helyes(honap));

    index = 1;
    while(honapok[index-1]!=honap){
        index++;
    }
    evszakindex = (index%12)/3 + 1;
    evszak = evszakok[evszakindex-1];
    cout << evszak << endl;
    return 0;
}
