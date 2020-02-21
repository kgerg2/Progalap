#ifndef CIRCLE_HPP_INCLUDED
#define CIRCLE_HPP_INCLUDED

#include "point.hpp"

class Circle {
private:
    Point origin;
    double r;
    
public:
    Circle(double r) : r(r) {}
    Circle(const Point &p, double r) : origin(p), r(r) {}
    
    bool contains(const Point &p) const {
        return origin.distance(p) <= r;
    }
};

#endif
