#ifndef POINT_HPP_INCLUDED
#define POINT_HPP_INCLUDED

#include <cmath>

class Point {
public:
    double x, y;
    
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    
    double distance(const Point &p) const {
        return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    }
};

#endif
