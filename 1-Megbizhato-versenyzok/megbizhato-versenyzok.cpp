#include <iostream>
#include <fstream>
#include <unistd.h>
#include <vector>

using namespace std;

int main()
{
    int i, j, hossz, d[6], minimum, maximum;
    vector<int> jok;
    //freopen(".\\1-Megbizhato-versenyzok\\be2.txt", "r", stdin);
    cin >> hossz;
    i = 0;
    while (cin >> d[0] >> d[1] >> d[2] >> d[3] >> d[4] >> d[5])
    {
        minimum = 9000;
        maximum = 0;
        for (j = 0; j < 6; j++)
        {
            if (d[j] == -1)
            {
                break;
            }
            if (minimum > d[j])
            {
                minimum = d[j];
            }
            if (maximum < d[j])
            {
                maximum = d[j];
            }
        }
        if (j == 6 && maximum - minimum <= 500)
        {
            jok.push_back(i+1);
        }
        i++;
    }
    cout << jok.size() << endl;
    for (i = 0; i < jok.size(); i++)
    {
        cout << jok[i] << " ";
    }
    cout << endl;
    //sleep(100);
    return 0;
}
