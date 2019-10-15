#include <iostream>

using namespace std;

int main(){
    int i, n, o, p, ido, beki, azon, l, db;
    cin >> n;
    int adat[n/2][2];
    l = 0;
    db = 0;
    while(cin >> o >> p >> beki >> azon){
        if(beki == 1 || beki == -1){
            ido = o*60+p;
            i = 0;
            while(i < db && adat[i][0] != azon) i++;
            if(beki == 1){
                adat[i][0] = azon;
                adat[i][1] = ido;
                if(i==db) db++;
            } else{
                if(ido - adat[i][1] > l) l = ido - adat[i][1];
                db--;
                adat[i][0] = adat[db][0];
                adat[i][1] = adat[db][1];
            }
        }
    }
    ido = 24*60;
    for(i=0; i<db; i++){
        if(ido - adat[i][1] > l) l = ido - adat[i][1];
    }
    cout << l << endl;
    return 0;
}
