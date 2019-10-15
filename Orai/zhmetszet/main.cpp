#include <iostream>

using namespace std;
/**< Ellen�rzi, hogy egy sorban egy pozit�v sz�m van-e be�rva. */
bool Helyes(int x){
    bool helyes = !cin.fail();
    if(helyes){
        helyes = cin.peek() == '\n';
    }
    if(!helyes){
        cin.clear();
        string tmp;
        getline(cin, tmp, '\n');
    } else{
        helyes = x > 0;
    }
    if(!helyes) cerr << "Hiba" << endl;
    return helyes;
}


int main()
{
    int n;
    do{
        cin >> n;
    } while (!Helyes(n));
    cout << "Hello world!" << endl;
    return 0;
}
