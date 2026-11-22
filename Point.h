#ifndef POINT_H
#define POINT_H

class Point {
private:
    double x, y;

public:
    Point(double x = 0, double y = 0);
    void SetPoint(double x, double y);
    double GetX() const;
    double GetY() const;
    void Show() const;
    double Distance(const Point& point) const;
};

#endif
