#include <iostream>
#include <fstream>

using namespace std;

int main(){
    int i, j, hossz, min, draga, ardb, max, ujmaxdb;
    //ifstream be (".\\5-Bor\\be2.txt");
    cin >> hossz;
    int l[hossz][2];
    i = 0;
    min = 0;
    draga = -1;
    ardb = 0;
    max = 0;
    ujmaxdb = -1;
    while(cin >> l[i][0] >> l[i][1]){
        if(l[min][0] > l[i][0]){
            min = i;
        }
        if(l[i][0] > 1000 && l[i][1] > draga){
            draga = l[i][1];
        }
        j = 0;
        while(l[i][1] != l[j][1]){
            j++;
        }
        if(j == i){
            ardb++;
        }
        if(l[i][0] > max){
            max = l[i][0];
            ujmaxdb++;
        }
        i++;
    }
    //be.close();

    cout << ++min << endl;

    cout << draga << endl;

    cout << ardb << endl;

    cout << ujmaxdb;
    max = l[0][0];
    for(i=1; i<hossz; i++){
        if(l[i][0] > max){
            max = l[i][0];
            cout << " " << i+1;
        }
    }
    cout << endl;
    return 0;
}