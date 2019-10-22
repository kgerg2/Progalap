#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
vector<long> primek;
vector<long> nagyonPrimek;


bool prim2(long kezd, long n){
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0 || n < 2) return false;
    while(kezd <= sqrt(n) && n % kezd != 0) kezd += 2;
    return n % kezd != 0;
}

bool prim(long n){
    long p;
    for(vector<long>::iterator it = primek.begin(); it != primek.end(); ++it) {
        if(n % *it == 0) return false;
        if(*it > sqrt(n)) return true;
    }
    cout << " " << n << endl;
    bool prim = prim2(*primek.end(), n);
    if(prim) primek.push_back(n);
    return prim;
}

long szelet(int i, long n){
    return n / pow(10, i-1);
}

int hossz(long n){
    return log10(n)+1;
}

void szamol(long szam){
    if(szam > INT_MAX) return;
    for(int i=1; i < 10; i += 2){
        if(i==5) continue;
        if(prim(szam*10+i)){
            nagyonPrimek.push_back(szam*10+i);
            szamol(szam*10+i);
        }
    }
}

int main()
{
    long szam;
    bool jo;
    primek.push_back(2);
    /*for(szam = 3; szam < 100; szam += 2){
        jo = true;
        for(int i = 1; i <= hossz(szam) && !jo; i++){
            jo = prim(szelet(i, szam));
        }
        if(jo){
            nagyonPrimek.push_back(szam);
            //cout << szam << endl;
        }
    }*/
    cout << prim(2) << endl;
    cout << prim(11) << endl;
    cout << prim(13) << endl;
    cout << prim(21) << endl;
    cout << prim(3) << endl;
    return 0;
    for(int kezdo = 0; kezdo < 10; kezdo++){
        if(prim(kezdo)){
            nagyonPrimek.push_back(kezdo);
            szamol(kezdo);
        }
    }

    /*for(long p : nagyonPrimek){
        cout << p << "\n";
    }*/
    //cout << nagyonPrimek.end() - nagyonPrimek.begin() << " db" << endl;
    for(vector<long>::iterator it = nagyonPrimek.begin(); it != nagyonPrimek.end(); ++it) {
        cout << *it << endl;
    }
    return 0;
}
