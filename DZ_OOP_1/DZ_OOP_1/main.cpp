#include <iostream>
#include <math.h>

using namespace std;
//�� ��������??
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
    void setx(double value) // �������� �������
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

// �� �������� ����
class Point
{
public:
    double x;
    double y;

    Point(double xx, double yy)
    {
        x = xx; y = yy;
        cout << "����� (x, y)..." << x << ", " << y << endl;
    }

    double distance(double xx, double yy)
    {
        double Line = sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
        return Line;
    }
};

