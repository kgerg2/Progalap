#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int x, fst, maxc, maxel;
    vector<int> v;
    ifstream f(".\\1.ora\\input.txt");
    if (!f.fail())
    {
        while (f >> x)
        {
            v.push_back(x);
        }
    }
    if (!v.size())
    {
        cout << "Hiba";
        return 1;
    }
    sort(v.begin(), v.end());
    fst = 0;
    maxc = 1;
    maxel = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] != v[i-1])
        {
            if (maxc < i - fst)
            {
                maxc = i - fst;
                maxel = v[fst];
            }
            fst = i;
        }
    }
    if (maxc < v.size() - fst)
    {
        maxel = v[fst];
    }
    cout << maxel << endl;
    return 0;
}
