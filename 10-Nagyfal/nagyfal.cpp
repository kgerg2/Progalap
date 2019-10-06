#include <iostream>
#include <fstream>

using namespace std;

int main(){
    int i, hossz, temp, orzottdb, orhiany, elsovedtelen, maxkezd, maxhossz, kezd, utolso_orzott;
    bool orzotton;
    //ifstream be (".\\10-Nagyfal\\be1.txt");
    cin >> hossz;
    bool l[hossz];
    i = 0;
    orzottdb = 0;
    orhiany = 0;
    elsovedtelen = 0;
    maxkezd = 0;
    maxhossz = 0;
    kezd = 0;
    orzotton = false;
    utolso_orzott = -1;
    while(cin >> temp){
        l[i] = temp > 0;
        if(l[i]){
            utolso_orzott = i;
            orzottdb++;
            if(i > 0 && !l[i-1]){
                orzottdb++;
            } else if(i > 0){
                if(!orzotton){
                    kezd = i-1;
                    orzotton = true;
                }
                if(i - kezd > maxhossz){
                    maxhossz = i - kezd;
                    maxkezd = kezd;
                }
            }
            
        } else{
            orzotton = false;
            if((i-utolso_orzott) % 2 == 0){
                if(elsovedtelen == 0) elsovedtelen = i;
                orhiany++;
            }
        }
        
        i++;
    }
    //be.close();
    if(l[i-1]) orzottdb--;

    cout << orzottdb << endl;

    cout << orhiany << endl;

    cout << elsovedtelen << endl;

    if(maxhossz > 0){
        cout << ++maxkezd << " " << maxkezd + maxhossz << endl;
    } else{
        cout << "0" << endl;
    }
    //cin >> i;
    return 0;
}