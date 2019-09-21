# include <iostream>
# include <fstream>

using namespace std;

int main(){
    int hossz, i, j, legdragabb, olcso, alaptdb, draga;
    //ifstream be (".\\3-Lakas\\be2.txt");
    cin >> hossz;
    int l[hossz][2], alapt[hossz];
    for(i=0; i<hossz; i++) alapt[i] = -1;
    i = 0;
    legdragabb = 0;
    olcso = 0;
    alaptdb = 0;
    draga = 0;
    while(cin >> l[i][0] >> l[i][1]){
        if(l[legdragabb][1] < l[i][1]){
            legdragabb = i;
        }
        if(l[i][0] > 100 && l[i][1] < 40){
            olcso++;
        }
        j = 0;
        while(alapt[j] != -1 && alapt[j] != l[i][0]){
            j++;
        }
        if(alapt[j] != l[i][0]){
            alapt[j] = l[i][0];
            alaptdb++;
        }
        if(l[i][1] > 100){
            draga++;
        }
        i++;
    }

    cout << ++legdragabb << endl;

    cout << olcso << endl;

    cout << alaptdb << endl;

    cout << draga;
    for(i=0; i<hossz; i++){
        if(l[i][1] > 100){
            cout << " " << i+1;
        }
    }
    cout << endl;
    
    return 0;
}