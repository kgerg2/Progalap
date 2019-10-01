#include <iostream>

using namespace std;

int main()
{
    unsigned int a, b, maradek, oszto;
    cerr << "LNKO\na, b: ";
    cin >> a >> b;
    if(a <= 0 || b <= 0){
        cerr << "Hiba";
    } else{
        if(a < b){
            /*unsigned int temp = a;
            a = b;
            b = temp;*/
            swap(a, b);
        }
        maradek = a % b;
        while(maradek > 0){
            a = b;
            b = maradek;
            maradek = a % b;
        }
        oszto = b;
        cout << oszto << endl;
    }
    return 0;
}
