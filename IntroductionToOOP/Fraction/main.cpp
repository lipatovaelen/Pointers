#include<iostream>
using namespace std;
// хранение дробного числа точно  ввиде двух целых чисел

//ОПИСАНИЕ КЛАССА
//описание класса - простую дробь

class simple_fraction
{
public:
    simple_fraction(int numerator, int denominator)
    {
        if (denominator == 0) // Ошибка деления на ноль
        cout << " делить на ноль нельзя \t " << this << endl;
    }

    // Определение основных математических операций для простой дроби
    double operator+ (int val) { return number() + val; } // Сложение
    double operator- (int val) { return number() - val; } // Вычитание
    double operator* (int val) { return number() * val; } // Умножение
    double operator/ (int val) // Деление
    {
        if (val == 0) {
            throw std::runtime_error("zero division error");
        }
        return number() / val;
    }
