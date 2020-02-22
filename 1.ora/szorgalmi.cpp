#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int x, fst, maxc, maxel;
    vector<int> v;
    vector<pair<int, int>> h; // érték - darabszám párok
    ifstream f("input.txt");
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
    sort(v.begin(), v.end()); // rendezés tétel
    maxc = 1;
    maxel = v[0];
    h.emplace_back(v[0], 1);
    for (int i = 1; i < v.size(); i++) // számlálás és maximum-kiválasztás
    {
        if (h.back().first == v[i])
        {
            h.back().second++;
            if (h.back().second > maxc)
            {
                maxel = h.back().first;
                maxc = h.back().second;
            }
            
        }
        else
        {
            h.emplace_back(v[i], 1);
        }
    }
    cout << maxel << endl;
    return 0;
}
