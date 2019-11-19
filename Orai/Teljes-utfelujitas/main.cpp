#include <iostream>

using namespace std;

bool HelyesHossz(int x){
    bool helyes = x >= 1 && x <= 10000;
    if(!helyes) cerr << "Hiba: Nem megfelelõ az út hossza." << endl;
    return helyes;
}

bool HelyesFelujitas(int x, int hossz){
    bool helyes = x >= 0 && x <= hossz;
    if(!helyes) cerr << "Hiba: Nem megfelelõek a felújítás adatai." << endl;
    return helyes;
}

bool HelyesDb(int x){
    bool helyes = x >= 1 && x <= 100;
    if(!helyes) cerr << "Hiba: Nem megfelelõ a felújítások száma." << endl;
    return helyes;
}

void utBeallitasa(int *ut, int hossz){
    for(int i = 0; i < hossz; i++){
        ut[i] = 0;
    }
}

int main()
{
    int ut[10001], hossz, db, kezd, veg, aszfaltozando;

    do {
        cin >> hossz;
    } while ( !HelyesHossz(hossz) );

    utBeallitasa(ut, hossz);
    aszfaltozando = hossz;

    do {
        cin >> db;
    } while ( !HelyesDb(db) );

    /*

    Ez a komment egy kicsit gyorsabb megoldást tartalmaz, ez nem a dolgozat része.

    for(int i = 1; i <= db; i++){
        do{
            cin >> kezd >> veg;
        } while(!HelyesFelujitas(kezd, hossz) || !HelyesFelujitas(veg, hossz));

        for(int j = kezd; j < veg; j++){
            aszfaltozando += ut[j] - 1;
            ut[j] = 1;
        }
    }

    cout << aszfaltozando << endl;

    */

    for (int i = 1; i <= db; i++) {
        do {
            cin >> kezd >> veg;
        } while ( !HelyesFelujitas(kezd, hossz) || !HelyesFelujitas(veg, hossz) );

        for (int j = kezd; j < veg; j++) {
            ut[j] = 1;
        }
    }

    for (int i = 0; i < hossz; i++) {
        aszfaltozando -= ut[i];
    }

    cout << aszfaltozando << endl;

    return 0;
}
