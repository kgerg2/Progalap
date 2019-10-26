#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int i, j, k, oradb, hossz, tanardb, tantargydb, tanar, nap;
    bool szakos, elfoglalt;
    //freopen(".\\1-Egy-napon-helyettesiteni-tudo-tanarok\\be4.txt", "r", stdin);
    //freopen(".\\1-Egy-napon-helyettesiteni-tudo-tanarok\\ki4_.txt", "w", stdout);
    cin >> hossz >> tanardb >> tantargydb >> tanar >> nap;
    int l[hossz][4], orak[hossz];
    i = oradb = 0;
    while(cin >> l[i][0] >> l[i][1] >> l[i][2] >> l[i][3]){
        if(l[i][0] == tanar && l[i][2] == nap){
            orak[oradb] = i;
            oradb++;
        }
        i++;
    }
    for(i=0; i<oradb; i++){
        j = 0;
        elfoglalt = false;
        szakos = false;
        while(j<tanardb && (elfoglalt || !szakos)){
            j++;
            if(j == tanar) continue;
            szakos = false;
            elfoglalt = false;
            for(k=0; k<hossz && !elfoglalt; k++){
                if(l[k][0] == j){
                    if(l[k][1] == l[orak[i]][1]) szakos = true;
                    if(l[k][2] == l[orak[i]][2] && l[k][3] == l[orak[i]][3]) elfoglalt = true;
                }
            }
        }
        if(!elfoglalt && szakos) orak[i] = j;
        else{
            cout << "-1\n";
            return 0;
        }
    }
    cout << oradb;
    for(i=0; i<oradb; i++) cout << " " << orak[i];
    cout << endl; // <- Enélkül nem fogadja el.
    return 0;
}