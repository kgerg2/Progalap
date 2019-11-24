#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int hul[1000], huldb, tdb, merdb, hkezd, elozo, uj;
    // freopen(".\\1-Sokaig-hidegebbe-valo-telepulesek\\be2.txt", "r", stdin);
    // freopen(".\\1-Sokaig-hidegebbe-valo-telepulesek\\ki2_.txt", "w", stdout);
    cin >> tdb >> merdb;
    huldb = 0;
    for (int i = 0; i < tdb; i++)
    {
        elozo = -50;
        hkezd = 1;
        int j = 0;
        while (j < merdb && j - hkezd < 8)
        {
            cin >> uj;
            // cout << uj << " ";
            if (uj >= elozo)
            {
                hkezd = j;
            }
            elozo = uj;
            j++;
        }
        // cout << endl;
        cin.ignore(4000, '\n');
        if (j - hkezd == 8)
        {
            hul[huldb] = i;
            huldb++;
        }
    }
    cout << huldb;
    for (int i = 0; i < huldb; i++)
    {
        cout << " " << hul[i] + 1;
    }
    cout << endl;
    return 0;
}
