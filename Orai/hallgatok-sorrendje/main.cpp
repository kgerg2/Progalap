#include <iostream>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Tanulo{
    int Ssz;
    int Ropi;
    int Cs;
    int Evf;
};

bool operator < (Tanulo x, Tanulo y)
{
    return (y.Evf > x.Evf) ||
           (y.Evf == x.Evf && y.Cs > x.Cs) ||
           (y.Evf == x.Evf && y.Cs == x.Cs && y.Ropi > x.Ropi);
}

bool operator <= (Tanulo x, Tanulo y)
{
    return (y.Evf > x.Evf) ||
           (y.Evf == x.Evf && y.Cs > x.Cs) ||
           (y.Evf == x.Evf && y.Cs == x.Cs && y.Ropi => x.Ropi);
}

bool operator > (Tanulo x, Tanulo y)
{
    return !x<=y;
}

void buborek(vector <Tanulo> &tanulok){
    for(int i=tanulok.size(); i>=1; i--){
        for(int j=0; j<i-1; j++){
            if(tanulok[j] < tanulok[j+1]){
                swap(tanulok[j], tanulok[j+1]);
            }
        }
    }
}

void qsort(vector <Tanulo> &tanulok){
    Tanulo t = tanulok[0];

}

int main()
{
    int N, c1, c2, i;
    vector <Tanulo> tanulok;
    Tanulo t;
    //freopen("be3.txt", "r", stdin);
    cin >> N;
    i = 1;
    while (cin >> t.Ropi >> c1 >> c2 >> t.Evf)
    {
        t.Cs = c1+c2;
        t.Ssz = i;
        tanulok.push_back(t);
        i++;
    }
    time_t kezd = clock();
    buborek(tanulok);
    //sort(tanulok.begin(), tanulok.end());
    //cerr << N;
    //Tanulo t1 = { 1, 2, 3 }, t2 = { 1, 2, 4 };
    //if(t1 <= t2) cerr << "ok" << endl;

    time_t vege = clock();

    for(int i=0; i<N; i++){
        //Tanulo x = tanulok[i];
        //cerr << x.Evf << " " << x.Cs << " " << x.Ropi << endl;
        cout << tanulok[i].Ssz << " ";
    }
    cout << endl;
    cerr << vege-kezd << endl;
    return 0;
}
