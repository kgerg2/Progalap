#include <iostream>

using namespace std;

const int maxN = 100;

bool Helyes(int x){
    bool helyes = x >= 0 && x <= maxN;
    if(!helyes) cerr << "Hiba: nem pozitiv vagy nagyobb, mint " << maxN << endl;
    return helyes;
}

bool T(int a, int b){
    return a > b;
}

int main()
{
    int N, Db, x[maxN];
    do{
        cerr << "Sorozat hossza: ";
        cin >> N;
    } while(!Helyes(N));

    for(int i=1; i<=N; i++){
        cerr << "A(z) " << i << ". elem: ";
        cin >> x[i-1];
    }

    Db = 0;
    for(int i=1; i<=N-1; i++){
        for(int j=i+1; j<=N; j++){
            if(T(x[i-1], x[j-1])){
                Db++;
            }
        }
    }
    cout << Db << endl;
    return 0;
}
