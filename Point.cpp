#include "Point.h"
#include <cmath>
#include <iostream>

Point::Point(double x, double y) : x(x), y(y) {}

void Point::SetPoint(double x, double y) {
    this->x = x;
    this->y = y;
}

double Point::GetX() const {
    return x;
}

double Point::GetY() const {
    return y;
}

void Point::Show() const {
    std::cout << "(" << x << ", " << y << ")";
}

double Point::Distance(const Point& point) const {
    return std::hypot(x - point.x, y - point.y);
}
