# include <iostream>
# include <fstream>

using namespace std;

int main(){
    int i, j, k, v, napdb, ordb, max, maxkezd, maxbef, kezd, sorozatban;
    //ifstream be (".\\7-Muzeum\\be2.txt");
    cin >> napdb >> ordb;
    int l[napdb];
    for(i=0; i<napdb; i++) l[i] = 0;
    i = 0;
    max = 0;
    while(cin >> k >> v){
        k--;
        if(v-k > max){
            max = v-k;
        }
        for(j=k; j<v; j++){
            l[j]++;
        }
    }
    //be.close();

    cout << max << endl;

    max = 0;
    sorozatban = 0;
    maxkezd = 0;
    maxbef = -1;
    for(i=0; i<napdb; i++){
        cout << l[i] << " ";
        if(l[i] > l[max]){
            max = i;
        }
        if(sorozatban){
            if(l[i] < 2){
                if(maxbef - maxkezd < i - kezd){
                    maxbef = i;
                    maxkezd = kezd;
                }
            } else{
                sorozatban = 0;
            }
        } else if(l[i] < 2){
            kezd = i;
            sorozatban = 1;
            if(maxbef - maxkezd < i - kezd){
                maxbef = i;
                maxkezd = kezd;
            }
        }
    }
    cout << endl;

    cout << ++max << endl;

    if(maxbef == -1){
        cout << 0;
    } else{
        cout << ++maxkezd << " " << ++maxbef << endl;
    }
    return 0;
}