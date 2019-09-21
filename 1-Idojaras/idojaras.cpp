# include <iostream>
# include <fstream>

using namespace std;

int main(){
    int i, hossz, fagy, maxpoz, hideg, valtdb;
    //ifstream be (".\\1-Idojaras\\be2.txt");
    cin >> hossz;
    int lista[hossz][2];
    i = 0;
    fagy = 0;
    maxpoz = 0;
    hideg = -2;
    valtdb = 0;
    while(cin >> lista[i][0] >> lista[i][1]){
        //cout << lista[i][0] << " " << lista[i][1] << endl;
        if(lista[i][0] <= 0){
            fagy++;
            if(lista[i][1] > 0){
                valtdb++;
            }
        }

        if(lista[i][1] - lista[i][0] > lista[maxpoz][1] - lista[maxpoz][0]){
            maxpoz = i;
        }

        if(i > 0 && hideg==-2 && lista[i][1] < lista[i-1][0]){
            hideg = i;
        }
        i++;
    }
    //be.close();

    cout << "#\n" << fagy;

    cout << "\n#\n" << maxpoz+1;

    cout << "\n#\n" << hideg+1;

    cout << "\n#\n" << valtdb;
    for(i=0;i<hossz;i++){
        if(lista[i][0] <= 0 && lista[i][1] > 0){
            cout << " " << i+1;
        }
    }
    cout << endl;
    //cin >> hossz;
    return 0;
}