#include <iostream>
//#include <stdio.h>

using namespace std;

int main()
{
    int tandb, spdb, nevdb, tan, sp, indulodbok[100], indulasok[1000], maxindulo, tobbszornevezo, keresett, egyszerredb, egyszerre[100][100];
    //freopen(".\\36-Sportnap\\be2.txt", "r", stdin);
    //freopen(".\\36-Sportnap\\ki2_.txt", "w", stdout);
    cin >> tandb >> spdb >> nevdb;
    int n[tandb][spdb];
    for (int i = 0; i < spdb; i++)
    {
        for (int j = 0; j < tandb; j++)
        {
            n[j][i] = 0;
        }
        indulodbok[i] = 0;
    }
    for (int i = 0; i < tandb; i++)
    {
        indulasok[i] = 0;
    }
    maxindulo = 0;
    tobbszornevezo = 10000;
    for (int i = 0; i < nevdb; i++)
    {
        cin >> tan >> sp;
        tan--;
        sp--;
        if (tan < tobbszornevezo && n[tan][sp] > 0)
        {
            tobbszornevezo = tan;
        }
        if (n[tan][sp] == 0)
        {
            indulasok[tan]++;
            if (indulasok[tan] > indulasok[maxindulo] || (indulasok[tan] == indulasok[maxindulo] && tan < maxindulo))
            {
                maxindulo = tan;
            }
        }
        n[tan][sp]++;
    }
    if (tobbszornevezo == 10000)
    {
        tobbszornevezo = -2;
    }
    
    cin >> keresett;
    keresett--;
    int keresettdb = 0;
    for (int i = 0; i < spdb; i++)
    {
        for (int j = i+1; j < spdb; j++)
        {
            egyszerre[i][j] = 1;
        }
    }
    for (int i = 0; i < tandb; i++)
    {
        for (int j = 0; j < spdb; j++)
        {
            for (int k = j+1; k < spdb; k++)
            {
                if (n[i][j] > 0 && n[i][k] > 0)
                {
                    egyszerre[j][k] = 0;
                }
            }
        }
        
        for (int j = 0; j < spdb; j++)
        {
            if (i == keresett)
            {
                keresettdb += n[i][j];
            }
            if (n[i][j] > 0)
            {
                indulodbok[j]++;
            }
        }
    }
    
    cout << "#\n" << keresettdb << endl;
    cout << "#\n" << tobbszornevezo + 1 << endl;
    cout << "#\n";
    for (int i = 0; i < spdb-1; i++)
    {
        cout << indulodbok[i] << " ";
    }
    cout << indulodbok[spdb-1] << endl;
    cout << "#\n" << maxindulo + 1 << endl;
    cout << "#\n";
    for (int i = 0; i < spdb; i++)
    {
        for (int j = i+1; j < spdb; j++)
        {
            if (egyszerre[i][j])
            {
                cout << i+1 << " " << j+1 << endl;
            }
        }
    }
    
    return 0;
}
