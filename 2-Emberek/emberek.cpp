# include <iostream>
# include <fstream>

using namespace std;

int main(){
    int hossz, i, max, b, kordb, fiataldb;
    int korok[200];
    for(i=0;i<200;i++) korok[i] = 0;
    //ifstream be (".\\2-emberek\\be2.txt");
    cin >> hossz;
    int l[hossz][2];
    i = 0;
    max = 0;
    b = 0;
    fiataldb = 0;
    while(cin >> l[i][0] >> l[i][1]){
        if(l[i][0] > l[max][0]){
            max = i;
        }
        if(l[i][0] > 40 && l[i][1] < 200000){
            b++;
        }
        korok[l[i][0]]++;
        if(l[i][0] < 30){
            fiataldb++;
        }
        i++;
    }

    cout << max+1 << endl;

    cout << b << endl;

    kordb = 0;
    for(i=0; i<200; i++){
        if(korok[i] > 0) kordb++;
    }
    cout << kordb << endl;

    cout << fiataldb;
    for(i=0;i<hossz;i++){
        if(l[i][0] < 30){
            cout << " " << i+1;
        }
    }
    cout << endl;
    cin >> hossz;
    return 0;
}