#include <iostream>
#include <vector>

using namespace std;

struct Proba{
    int Magassag;
    int Db;
    bool Siker;
};

void beolvas(vector<vector<Proba> > &emberek){
    int N, M;
    Proba seged;
    vector<Proba> egyproba;
    emberek.push_back(egyproba);
    char c;
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> M;
        for(int j=1; j<=M; j++){
            cin >> seged.Magassag >> seged.Db >> c;
            seged.Siker = c == 'y';
            egyproba.push_back(seged);
        }
        emberek.push_back(egyproba);
        egyproba.clear();
    }
    //cout << emberek.size() << endl;
}

Proba legjobbugras(vector<Proba> x){
    Proba maximum;
    maximum.Magassag = -1;
    maximum.Db = 4;
    maximum.Siker = false;
    int i=x.size()-1;
    while (i >= 0 && !x[i].Siker) i--;
    if (i >= 0) maximum = x[i];
    //cout << i << maximum.Db << " " << maximum.Magassag << " " << maximum.Siker << endl;
    return maximum;
}

bool kisebb(vector<Proba> x, vector<Proba> y){
    return (legjobbugras(x).Magassag < legjobbugras(y).Magassag) ||
           (legjobbugras(x).Magassag == legjobbugras(y).Magassag && legjobbugras(x).Db > legjobbugras(y).Db) ||
           (legjobbugras(x).Magassag == legjobbugras(y).Magassag && legjobbugras(y) == y[0]);
}

void rendez(vector<vector<Proba> > emberek, vector<int> &index){
    //cout << emberek.size() << endl;
    for(int i=0; i<emberek.size(); i++) index.push_back(i);
    //cout << index.size() << endl;
    for(int i=1; i<emberek.size(); i++){
        for(int j=i+1; j<emberek.size(); j++){
            if(kisebb(emberek[index[i]], emberek[index[j]])){
                swap(index[i], index[j]);
            }
        }
    }

}

void kiir(vector<int> index){
    for(int i=1; i<index.size(); i++){
        cout << index[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector < vector <Proba> > emberek;
    vector <int> index;
    beolvas(emberek);
    rendez(emberek, index);
    kiir(index);
    return 0;
}
