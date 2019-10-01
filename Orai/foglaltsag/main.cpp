#include <iostream>

using namespace std;

const int maxN = 100, maxM = 100;

bool HelyesN(int x){
    bool helyes = x >= 0 && x <= maxN;
    if(!helyes) cerr << "Hiba: nem pozitiv vagy nagyobb, mint " << maxN << endl;
    return helyes;
}

bool HelyesM(int x){
    bool helyes = x >= 0 && x <= maxM;
    if(!helyes) cerr << "Hiba: nem pozitiv vagy nagyobb, mint " << maxM << endl;
    return helyes;
}

bool T(bool x[maxN][maxM], int i, int j){
    return !x[i-1][j-1] && !x[i-1][j];
}

int main()
{
    int N, M, a, b;
    bool x[maxN][maxM];
    bool Vane;
    do{
        cerr << "Sorok szama: ";
        cin >> N;
    } while(!HelyesN(N));
    do{
        cerr << "Szekek szama: ";
        cin >> M;
    } while(!HelyesM(M));

    char c;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cerr << i << ". sor, " << j << ". szek: ";
            cin >> c;
            x[i-1][j-1] = c == 'y';
        }
    }
    int i=1, j;
    Vane = false;
    while(i <= N && !Vane){
        j = i;
        while(j < M && !Vane){
            Vane = T(x, i, j);
            j++;
        }
        i++;
    }
    if(Vane){
        a = i-1;
        b = j-1;
        cout << a << " " << b << endl;
    } else{
        cout << "Nincs." << endl;
    }
    return 0;
}
