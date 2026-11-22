#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "Point.h"

class Shape {
protected:
    Point firstPoint;
    Shape(const Point& point);

public:
    virtual ~Shape() = default;
    virtual void ShowVertices() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(const Point& center = Point(), double radius = 0);
    void SetCircle(const Point& center, double radius);
    Point GetCenter() const;
    double GetRadius() const;
    void ShowVertices() const override;
    double Perimeter() const override;
    double Area() const override;
};

class Square : public Shape {
private:
    double side;

public:
    Square(const Point& topLeft = Point(), double side = 0);
    void SetSquare(const Point& topLeft, double side);
    Point GetTopLeft() const;
    double GetSide() const;
    void ShowVertices() const override;
    double Perimeter() const override;
    double Area() const override;
};

class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(const Point& topLeft = Point(), double length = 0, double width = 0);
    void SetRectangle(const Point& topLeft, double length, double width);
    Point GetTopLeft() const;
    double GetLength() const;
    double GetWidth() const;
    void ShowVertices() const override;
    double Perimeter() const override;
    double Area() const override;
};

class Triangle : public Shape {
private:
    Point secondPoint, thirdPoint;

public:
    Triangle(const Point& a = Point(), const Point& b = Point(), const Point& c = Point());
    void SetTriangle(const Point& a, const Point& b, const Point& c);
    void GetVertices(Point& a, Point& b, Point& c) const;
    void ShowVertices() const override;
    double Perimeter() const override;
    double Area() const override;
};

#endif
