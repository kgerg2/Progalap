#include <iostream>

using namespace std;

long int fakt(unsigned int x)
{
    /*if(x < 2) return 1;
    return fakt(x-1) * x;*/
    return x < 2 ? 1 : x * fakt(x-1);
}

int main()
{
    unsigned int n; /**< Negatív bemenetet is pozitívként értelmez. */
    long int r;
    cerr << "n!\nn: ";
    cin >> n;
    r = fakt(n);
    cerr << "n! = ";
    cout << r << endl;
    return 0;
}
