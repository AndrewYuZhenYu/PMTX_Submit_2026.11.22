#include "Geometry.h"
#include <iostream>
#include <string>

bool ReadNumber(double &number)
{
    int next = std::cin.peek();
    while (next == ' ' || next == '\t' || next == '\r')
    {
        std::cin.get();
        next = std::cin.peek();
    }
    return bool(std::cin >> number);
}

bool FinishLine(bool valid)
{
    if (std::cin.eof())
    {
        return valid;
    }

    std::cin.clear();
    std::string rest;
    std::getline(std::cin, rest);
    return valid && rest.find_first_not_of(" \t\r") == std::string::npos;
}

bool ReadPoint(const char *prompt, Point &point)
{
    while (std::cin)
    {
        std::cout << prompt;
        double x, y;
        if (FinishLine(ReadNumber(x) && ReadNumber(y)))
        {
            point.SetPoint(x, y);
            return true;
        }
        if (std::cin)
        {
            std::cout << "请输入两个数字，用空格分隔。\n";
        }
    }
    return false;
}

bool ReadSize(const char *prompt, double &size)
{
    while (std::cin)
    {
        std::cout << prompt;
        if (FinishLine(ReadNumber(size) && size > 0))
        {
            return true;
        }
        if (std::cin)
        {
            std::cout << "请输入一个大于 0 的数字。\n";
        }
    }
    return false;
}

void ShowResult(const Shape &shape)
{
    shape.ShowVertices();
    std::cout << "周长：" << shape.Perimeter() << '\n';
    std::cout << "面积：" << shape.Area() << '\n';
}

int main()
{
    std::cin >> std::noskipws;
    std::cout << std::fixed;
    std::cout.precision(2);

    std::cout << "圆\n";
    Point center;
    double radius;
    if (!ReadPoint("请输入圆心坐标 x y：", center) ||
        !ReadSize("请输入半径：", radius))
    {
        return 0;
    }
    Circle circle;
    circle.SetCircle(center, radius);
    std::cout << "半径：" << circle.GetRadius() << '\n';
    ShowResult(circle);

    std::cout << "\n正方形\n";
    Point squareTopLeft;
    double side;
    if (!ReadPoint("请输入左上角坐标 x y：", squareTopLeft) ||
        !ReadSize("请输入边长：", side))
    {
        return 0;
    }
    Square square;
    square.SetSquare(squareTopLeft, side);
    std::cout << "边长：" << square.GetSide() << '\n';
    ShowResult(square);

    std::cout << "\n矩形\n";
    Point rectangleTopLeft;
    double length, width;
    if (!ReadPoint("请输入左上角坐标 x y：", rectangleTopLeft) ||
        !ReadSize("请输入长：", length) || !ReadSize("请输入宽：", width))
    {
        return 0;
    }
    Rectangle rectangle;
    rectangle.SetRectangle(rectangleTopLeft, length, width);
    std::cout << "长：" << rectangle.GetLength()
            << "，宽：" << rectangle.GetWidth() << '\n';
    ShowResult(rectangle);

    std::cout << "\n三角形\n";
    Point a, b, c;
    if (!ReadPoint("请输入第一个顶点坐标 x y：", a) ||
        !ReadPoint("请输入第二个顶点坐标 x y：", b) ||
        !ReadPoint("请输入第三个顶点坐标 x y：", c))
    {
        return 0;
    }
    Triangle triangle;
    triangle.SetTriangle(a, b, c);
    triangle.GetVertices(a, b, c);
    std::cout << "三条边长：" << a.Distance(b) << "、"
            << b.Distance(c) << "、" << c.Distance(a) << '\n';
    ShowResult(triangle);

    return 0;
}
