#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    double a, b;
    double x;
    cerr << "ax+b=0\na es b:";
    cin >> a >> b;
    if(a == 0){
        cerr << "Hiba: a nem lehet 0\n";
        exit(1);
    }
    x = -b/a;
    cerr << "x = ";
    cout << x << endl;
    return 0;
}
