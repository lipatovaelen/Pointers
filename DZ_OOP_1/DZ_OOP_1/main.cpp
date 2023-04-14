#include <iostream>
#include <math.h>

using namespace std;
//не работает??
/*
class Point
{
    double x, y;
public:
    double getx()
    {
        return x;
    }
    double gety()
    {
        return y;
    }
    void setx(double value) // аргумент функции
    {
        x = value;
    }
    void sety(double value)
    {
        y = value;
    }
    Point(double first, double second)
    {
        x = first;
        y = second;
    }
    double length(Point b)
    {
        return sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
    }
};

*/

// не работает тоже
class Point
{
public:
    double x;
    double y;

    Point(double xx, double yy)
    {
        x = xx; y = yy;
        cout << "Точка (x, y)..." << x << ", " << y << endl;
    }

    double distance(double xx, double yy)
    {
        double Line = sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
        return Line;
    }
};

