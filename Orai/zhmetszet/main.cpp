#include <iostream>

using namespace std;
/**< Ellenõrzi, hogy egy sorban egy pozitív szám van-e beírva. */
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
