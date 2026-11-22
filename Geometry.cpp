#include "Geometry.h"
#include <cmath>
#include <iostream>

const double PI = 3.141592653589793;

static void ShowCorners(const Point& topLeft, double length, double width) {
    double x = topLeft.GetX();
    double y = topLeft.GetY();

    std::cout << "顶点：";
    topLeft.Show();
    std::cout << " ";
    Point(x + length, y).Show();
    std::cout << " ";
    Point(x + length, y - width).Show();
    std::cout << " ";
    Point(x, y - width).Show();
    std::cout << '\n';
}

Shape::Shape(const Point& point) : firstPoint(point) {}

Circle::Circle(const Point& center, double radius)
    : Shape(center), radius(radius) {}

void Circle::SetCircle(const Point& center, double radius) {
    firstPoint = center;
    this->radius = radius;
}

Point Circle::GetCenter() const {
    return firstPoint;
}

double Circle::GetRadius() const {
    return radius;
}

void Circle::ShowVertices() const {
    std::cout << "圆心：";
    GetCenter().Show();
    std::cout << '\n';
}

double Circle::Perimeter() const {
    return 2 * PI * radius;
}

double Circle::Area() const {
    return PI * radius * radius;
}

Square::Square(const Point& topLeft, double side)
    : Shape(topLeft), side(side) {}

void Square::SetSquare(const Point& topLeft, double side) {
    firstPoint = topLeft;
    this->side = side;
}

Point Square::GetTopLeft() const {
    return firstPoint;
}

double Square::GetSide() const {
    return side;
}

void Square::ShowVertices() const {
    ShowCorners(GetTopLeft(), side, side);
}

double Square::Perimeter() const {
    return 4 * side;
}

double Square::Area() const {
    return side * side;
}

Rectangle::Rectangle(const Point& topLeft, double length, double width)
    : Shape(topLeft), length(length), width(width) {}

void Rectangle::SetRectangle(const Point& topLeft, double length, double width) {
    firstPoint = topLeft;
    this->length = length;
    this->width = width;
}

Point Rectangle::GetTopLeft() const {
    return firstPoint;
}

double Rectangle::GetLength() const {
    return length;
}

double Rectangle::GetWidth() const {
    return width;
}

void Rectangle::ShowVertices() const {
    ShowCorners(GetTopLeft(), length, width);
}

double Rectangle::Perimeter() const {
    return 2 * (length + width);
}

double Rectangle::Area() const {
    return length * width;
}

Triangle::Triangle(const Point& a, const Point& b, const Point& c)
    : Shape(a), secondPoint(b), thirdPoint(c) {}

void Triangle::SetTriangle(const Point& a, const Point& b, const Point& c) {
    firstPoint = a;
    secondPoint = b;
    thirdPoint = c;
}

void Triangle::GetVertices(Point& a, Point& b, Point& c) const {
    a = firstPoint;
    b = secondPoint;
    c = thirdPoint;
}

void Triangle::ShowVertices() const {
    std::cout << "顶点：";
    firstPoint.Show();
    std::cout << " ";
    secondPoint.Show();
    std::cout << " ";
    thirdPoint.Show();
    std::cout << '\n';
}

double Triangle::Perimeter() const {
    return firstPoint.Distance(secondPoint) + secondPoint.Distance(thirdPoint)
           + thirdPoint.Distance(firstPoint);
}

double Triangle::Area() const {
    double x1 = secondPoint.GetX() - firstPoint.GetX();
    double y1 = secondPoint.GetY() - firstPoint.GetY();
    double x2 = thirdPoint.GetX() - firstPoint.GetX();
    double y2 = thirdPoint.GetY() - firstPoint.GetY();
    return std::fabs(x1 * y2 - y1 * x2) / 2;
}
