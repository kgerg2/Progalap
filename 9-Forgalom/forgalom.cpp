# include <iostream>
# include <fstream>

using namespace std;

int main(){
    int i, j, nap, elonap, uzl, db, napdb, uzldb, hossz, max, jonap, maxkezd, maxveg, kezd, benne, maxdb, ossz;
    //ifstream be (".\\9-Forgalom\\be2.txt");
    cin >> napdb >> uzldb >> hossz;
    int u[uzldb][napdb];
    for(i=0; i<uzldb; i++){
        for(j=0; j<napdb; j++){
            u[i][j] = 0;
        }
    }

    max = 0;
    elonap = -1;
    jonap = 0;
    maxkezd = 0;
    maxveg = -1;
    while(cin >> nap >> uzl >> db){
        if(db > max){
            max = db;
        }
        if(elonap != nap){
            jonap++;
        }
        u[uzl-1][nap-1] = 1;
        if(nap - elonap > 1){
            kezd = nap;
        }
        if(maxveg - maxkezd < nap - kezd){
            maxkezd = kezd;
            maxveg = nap;
        }
        elonap = nap;
    }
    //be.close();

    cout << max << endl;

    cout << jonap << endl;

    max = 0;
    maxdb = 0;
    for(i=0; i<uzldb; i++){
        ossz = 0;
        for(j=0; j<napdb; j++){
            ossz += u[i][j];
        }
        if(ossz > maxdb){
            max = i;
            maxdb = ossz;
        }
    }
    cout << ++max << " " << maxdb << endl;

    cout << maxkezd << " " << maxveg << endl;
    return 0;
}