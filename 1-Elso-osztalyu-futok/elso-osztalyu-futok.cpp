#include <iostream>
#include <fstream>

using namespace std;

int main(){
    int i, db, hossz, hatar;
    //fstream be (".\\1-Elso-osztalyu-futok\\be2.txt");
    cin >> hossz >> hatar;
    int l[hossz];
    i = 0;
    db = 0;
    while (cin >> l[i]){
        if(l[i] >= hatar) db++;
        i++;
    }
    //be.close();
    cout << db;
    for(i=0; i<hossz; i++){
        if(l[i] >= hatar){
            cout << " " << i+1;
        }
    }
    return 0;
}