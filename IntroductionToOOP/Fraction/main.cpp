#include<iostream>
using namespace std;
// �������� �������� ����� �����  ����� ���� ����� �����

//�������� ������
//�������� ������ - ������� �����

class simple_fraction
{
public:
    simple_fraction(int numerator, int denominator)
    {
        if (denominator == 0) // ������ ������� �� ����
        cout << " ������ �� ���� ������ \t " << this << endl;
    }

    // ����������� �������� �������������� �������� ��� ������� �����
    double operator+ (int val) { return number() + val; } // ��������
    double operator- (int val) { return number() - val; } // ���������
    double operator* (int val) { return number() * val; } // ���������
    double operator/ (int val) // �������
    {
        if (val == 0) {
            throw std::runtime_error("zero division error");
        }
        return number() / val;
    }
