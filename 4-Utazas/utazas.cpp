#include <iostream>
#include <fstream>

using namespace std;

int main(){
    int i, j, hossz, tavoli, legdragabb, db, draga;
    //ifstream be (".\\4-Utazas\\be2.txt");
    cin >> hossz;
    int l[hossz][2], ar[hossz][2];
    for(i=0; i<hossz; i++) ar[i][0] = 0;
    i = 0;
    tavoli = 0;
    legdragabb = -1;
    draga = 0;
    while(cin >> l[i][0] >> l[i][1]){
        if(l[tavoli][0] < l[i][0]){
            tavoli = i;
        }
        if(l[i][0] < 1000 && l[i][1] > legdragabb){
            legdragabb = l[i][1];
        }
        j = 0;
        while(ar[j][0] != l[i][1] && ar[j][0] != 0 && j<i){
            j++;
        }
        if(ar[j][0] == l[i][1]){
            ar[j][1]++;
        } else{
            ar[j][0] = l[i][0];
            ar[j][1] = 1;
        }
        if((double)l[i][1]/l[i][0] > 100){
            draga++;
        }
        i++;
    }
    //be.close();

    cout << ++tavoli << endl;

    cout << legdragabb << endl;

    db = 0;
    i = 0;
    while(ar[i][0] > 0 && i < hossz){
        if(ar[i][1] == 1){
            db++;
        }
        i++;
    }
    cout << db << endl;

    cout << draga;
    for(i=0; i<hossz; i++){
        if((double)l[i][1]/l[i][0] > 100){
            cout << " " << i+1;
        }
    }
    cout << endl;
    return 0;
}