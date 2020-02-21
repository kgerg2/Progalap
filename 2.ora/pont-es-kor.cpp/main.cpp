#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

class Pont
{
private:
    float x, y;
public:
    Pont(float x = 0, float y = 0): x(x), y(y) {}
    float getX() const
    {
        return x;
    }
    float getY() const
    {
        return y;
    }
    void setX(float x)
    {
        this->x = x;
    }
    void setY(float y)
    {
        this->y = y;
    }
    float tav(const Pont &p) const
    {
        return sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y));
    }
};

class Kor
{
private:
    Pont o;
    float r;
public:
    Kor(Pont o, float r): o(o), r(r) {}
    bool benne(const Pont &p) const
    {
        return o.tav(p) <= r;
    }
};

int main()
{
    vector<Pont> v;
    float x, y, r;
    ifstream f("input.txt");
    f >> x >> y >> r;
    Kor k(Pont(x, y), r);
    while(f >> x >> y){
        v.emplace_back(x, y);
    }
    bool l = false;
    unsigned int i = 0;
    while(!l && i < v.size()){
        l = k.benne(v[i]);
        i++;
    }
    cout << i << ". pont (" << v[i-1].getX() << ", " << v[i-1].getY() << ")\n";
    return 0;
}
