#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
//    int i, a, b, c, max, maxi=-1;
//    i = 0;
//    while(cin >> c){
//        if(i >= 2 && a > b && c > b && b > maxi){
//            maxi = i;
//            max = b;        }
//        a = b;
//        b = c;
//        i++;
//    }
//    cout << maxi << " " << max << endl;

    string s = "be2.txt";
    ifstream f(s);
    if (f.fail()){
        cout << "Hiba." << endl;
        return 1;
    }
    vector<int> x;
    int e, mx, ind;
    bool l;
    while(f >> e){
        x.push_back(e);
    }
    l = false;

    for(int i = 1; i < x.size() - 1; i++){
        if(l && (x[i-1] > x[i] && x[i] < x[i+1])){
            if(mx < x[i]){
                mx = x[i];
                ind = i;
            }
        } else if(x[i-1] > x[i] && x[i] < x[i+1]){
            l = true;
            mx = x[i];
            ind = i;
        }
    }

    cout << mx << " " << ind << endl;
    return 0;
}
