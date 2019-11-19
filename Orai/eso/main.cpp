#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

const int Nmax = 1000;

bool HelyesN(int x){
    bool helyes = x >= 0 && x <= Nmax;
    if(!helyes) cerr << "Hiba: N nem pozitiv vagy nagyobb, mint " << Nmax << endl;
    return helyes;
}

/*void beolvas(int &N, int csap[Nmax][7]){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<7; j++){
            cin >> csap[i][j];
        }
    }
}*/

void beolvas(int &N, vector < vector <int> > & csap){
    cin >> N;
    int x;
    for(int i=0; i<N; i++){
        csap.push_back(vector<int>());
        for(int j=0; j<7; j++){
            cin >> x;
            csap[i].push_back(x);
        }
    }
}

bool egyretobb(vector <int> x){
    int i = 0;
    while(i < 6 && x[i] < x[i+1]){
        i++;
    }
    return i == 6;
}

int main()
{
    int N, maxi, db;
    vector < vector <int> > csap;
    vector <int> esos;
    //freopen("be1.txt", "r", stdin);
    beolvas(N, csap);
    int leh[N];
    maxi = 1;
    for(int i=0; i<N; i++){
        leh[i] = 0;
        for(int j = 0; j<7; j++){
            leh[i] += csap[i][j];
        }
        if(leh[maxi] < leh[i]){
            maxi = i;
        }
    }

    for(int i=0; i<N; i++){
        cout << leh[i] << " ";
    }
    cout << endl << maxi + 1 << endl;

    db = 0;
    for(int i=0; i<N; i++){
        if(egyretobb(csap[i])){
            esos.push_back(i+1);
            db++;
        }
    }
    cout << db;
    for(int i=0; i<db; i++){
        cout << " " << esos[i];
    }
    cout << endl << endl << endl;
    return 0;
}
