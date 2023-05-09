#include<iostream>
using namespace std;

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction left, const Fraction right);

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	// Конструктор: перзагрузка
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstruct:\t" << this << endl;//Конструкция по умолчанию
	}

	Fraction(int integer) //конструктор с одним параметром
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;

	}

	Fraction(int numerator, int denominator)//конструктор с двумя параметрами
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
	}

	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}

	~Fraction()
	{
		cout << "Denominator:\t" << this << endl;
	}


	//operator
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:" << this << endl;
		return *this;

	}

	Fraction& operator*=(const Fraction& other)
	{
		int a = 2;
		int b = 3;
		a *= b;
		a /= b;
		// a == 2;
		return *this = *this * other;
	}

	Fraction operator++(int)
	{
		to_proper();
		Fraction old = *this;
		integer++;
		return old;
	}


	// Metods:

	//умножение дроби метод  -перевод правильной дроби в неправильную прямой метод
	Fraction& to_improper() //метод поведение объекта - для перегрузки класса (умножение дроби) 
	{
		numerator += integer * denominator;
		integer = 0;//обнуляем intege
		return *this; //вернуть указатель на наш обект
	}

	//метод возврат дроби в стандартный вид
	Fraction& to_proper()//перевод неправильной дроби в правильную обратный метод
	{
		integer += numerator / denominator;
		numerator %= denominator;
	}

	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}

};

Fraction operator*(Fraction left, Fraction right)//перегрузка класса для дроби
//дроби
{
	left.to_improper();
	right.to_improper();
	//реаизация умножения сет методами задаем переменные члены класса
	/*Fraction result; //объект в котором сохраним результат
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());*/


	//реализация умножения без сет методов  вызывая конструктор 
	/*Fraction result
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	);
	result.to_proper(); //перевод дроби в правильную

	return result;//вернуть результат*/

	//реализация одной строкой сразу в результате
	//прямо в return создаем временный быземянный обект типа Fraction
	//временный быземянный обект существуют в пределах одного выражения и 
	//удаляются из памяти по завершению выраженичя
	return Fraction
	(
		left.get_numerator()*right.get_numerator(), 
		left.get_denominator()*right.get_denominator()
	).to_proper();

}

//#define CONSTRUCTORS_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK



	int a;
	Fraction A;//default constractor
	A.print();

	Fraction B = 5; // конструктор с одним параметром
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();
#endif // CONSTRUCTORS_CHECK

	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	Fraction C = A * B;
	A.print();
	B.print();
	C.print();


}