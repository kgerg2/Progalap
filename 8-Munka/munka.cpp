# include <iostream>
# include <fstream>

using namespace std;

int main(){
    int i, j, ceg, cegdb, cdb, kdb, holgy, ur;
    //fstream be (".\\8-Munka\\be2.txt");
    cin >> cegdb >> kdb;
    int c[cegdb], k[kdb][3];
    for(i=0; i<cegdb; i++) c[i] = 0;
    i = 0;
    holgy = 0;
    while(cin >> ceg >> k[i][0] >> k[i][1] >> k[i][2]){
        if(k[i][2] == 0){
            holgy++;
        }
        c[--ceg]++;
        i++;
    }
    //be.close();

    ur = kdb-holgy;
    cout << holgy << " " << ur << endl;

    cdb = 0;
    for(i=0; i<cegdb; i++){
        if(c[i] > 0){
            cdb++;
        }
    }
    cout << cdb << endl;

    for(i=0; i<cegdb; i++){
        cout << c[i] << " ";
    }
    cout << endl;

    i = 0;
    j = holgy;
    while(i<holgy || j<kdb){
        if (j < kdb && (i == holgy || k[i][1] > k[j][1])){
            cout << k[j][0] << " ";
            j++;
        } else{
            cout << k[i][0] << " ";
            i++;
        }
    }
    cout << endl;
    return 0;
}