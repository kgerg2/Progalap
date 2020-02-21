#include <iostream>
#include <fstream>
#include <vector>

#include "point.hpp"
#include "circle.hpp"

using namespace std;

bool search(const Circle &c, const vector<Point> &t, unsigned int &ind); 

int main() {
    // előkészítés
    cout << "Irja be a fajl nevet: ";
    string file; cin >> file;
    ifstream f(file);
    
    // hibaellenőrzés
    if (f.fail()) {
        cout << "Hiba tortent a fajl megnyitasa soran." << endl;
        return 1;
    }
    
    // beolvasás
    double x, y, r;
    f >> x >> y >> r;
    Circle c(Point(x, y), r);
    
    vector<Point> t;
    while (f >> x >> y) {
        t.push_back(Point(x, y));
    }
    
    // megoldás és kiírás
    unsigned int ind;
    if (search(c, t, ind)) {
        cout << "A (" << t[ind].x << "," << t[ind].y
             << ") koordinataju pont benne van a korben." << endl;
    } else {
        cout << "Egyik pont sincs benne a korben." << endl;
    }
    
    return 0;
}

// eldönti, hogy van-e olyan pont a t tömbben, ami a c körben van,
// és az ind változóba tárolja egy ilyen tulajdonságú pont indexét (ha van)
bool search(const Circle &c, const vector<Point> &t, unsigned int &ind) {
    /* lineáris keresés
     * feltétel             felt(i) ~ c.contains(t[i])
     */
    bool l = false;
    for (unsigned int i = 0; !l && i < t.size(); ++i) {
        l = c.contains(t[i]);
        ind = i;
    }
    
    return l;
    
/*
    bool l = false;
    for (ind = 0; !l && ind < t.size(); ++ind) {
        l = c.contains(t[ind]);
    }
    
    return l;
*/
    
/*  
    for (ind = 0; ind < t.size(); ++ind) {
        if (c.contains(t[i]) {
            return true;
        }
    }
    
    return false;
*/
}
