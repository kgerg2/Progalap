#include <iostream>

using namespace std;

string all[60];
int faj[60], eszidb[60], eszi[60][60];

void frissit(int ssz, int uj){
    faj[ssz] = uj;
    for(int i=0; i<eszidb[ssz]; i++){
        if(faj[eszi[ssz][i]])
    }
}

int main()
{
    int i, j, a1ssz, db, alldb;
    bool a1novevo, a1rag;
    string a1, a2;
    cin >> db;

    for(i=0; i<db*2; i++) eszidb[i] = 0;
    i = 0;
    alldb = 0;
    while(cin >> a1 >> a2){
        cout << "(" << a1 << ", " << a2 << ")\n";
        a1rag = false;
        j = 0;
        while(j<alldb && a2 != all[j]){
            j++;
        }
        a1ssz = j;
        if(j==alldb){
            all[alldb] = a2;
            faj[alldb] = 0;
            cout << all[alldb] << " 0\n";
            alldb++;
            a1rag = false;
        } else{
            a1rag = faj[j] > 0;
        }

        j = 0;
        while(j<alldb && a1 != all[j]){
            j++;
        }
        eszi[a1ssz][eszidb[a1ssz]] = j;
        eszidb[a1ssz]++;
        if(j==alldb){
            all[alldb] = a1;
            faj[alldb] = a1rag ? 2 : 1;
            cout << all[alldb] << " " << faj[alldb] << endl;
            alldb++;
        } else if(a1rag && faj[j]!=2){
            faj[j] = 2;

            cout << all[j] << " " << faj[j] << endl;
            /** többi frissítése! */
        }
        i++;
    }
    //cout << jodb << endl;
    for(i=0; i<alldb; i++){
        if(faj[i] == 1){
            cout << all[i] << endl;
        }
    }
    return 0;
}
