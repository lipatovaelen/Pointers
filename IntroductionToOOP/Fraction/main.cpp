#include<iostream>
using namespace std;
//прототип функции умножения 
class Fraction;
Fraction operator*(Fraction left, Fraction right);

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

  // конструкторы=======================================================

	Fraction() //Default constructor конструктор по умолчанию -----------------
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstruct:\t" << this << endl;
	}
	Fraction(int integer) //конструктор с одним параметром----------------
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		
	}
	Fraction(int numerator, int denominator) //конструктор с двумя параметрами
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);//чтобы в знаменатель не попал ноль фильтрация данных
	}

	//универсальный конструктор --------------------------------
	Fraction(int integer, int numerator, int dedenominator = 1)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}

	// конструктор копирования
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}

	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//Секция Операторы==================================
	//оператор присваивания
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	//оператор умножить*присвоить код перегрузки
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}

	//оператор разделить/присвоить код перегрузки
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this / other;
	}

	//перегрузка оператора инкримент/декремент
	Fraction& operator++()//префиксный инкремент перегрузка ++1
	{
		to_proper();
		integer++;
		return *this;
	}
	Fraction& operator++(int)//постфиксный инкремент перегрузка 1++
	{
		//всегда принимает один и только один параметр типа (int)
		//это позволяет компилятору на уровне перегрузки функций отличить
		//постфиксный инкримент от префиксного
		//преиксный выполняется самый первый постфиксный самый послединй
		to_proper();
		Fraction old = *this;
		integer++;
		return old;
	}


	// секция Методы: ===================================
	// метод перевод правильной дроби в неправильную - обеспечивает поведение объекта------------
	Fraction& to_improper()
	{
		numerator += integer * denominator; 
		integer = 0; //обнуляем, 
		return *this; //
	}
	// метод перевод неправильную  дробь в правильную - обеспечивает поведение объекта------------
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this; //
	}
	//метод "обращения" дроби - числитель и занменатель меняются местами
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		inverted.numerator ^= inverted.denominator;
		inverted.denominator ^= inverted.numerator;
		inverted.numerator ^= inverted.denominator;
	}

	//метод сокращения дроби - используем алгоритма Евклида
	//more - большее, less-меньшее, rest-остаток от деления;
	Fraction& reduce()
	{
		int more, less, rest;
		if (numerator > denominator)more = numerator, less = denominator;
		else less = numerator, more = denominator;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more;//наибольший общий делитель
		numerator /= GCD;
		denominator /= GCD;
		return *this;
		
	}

	// метод вывода дроби на экран-----------
	void print()const
	{
		if (integer)cout << integer; // если только целая часть, выводим ее
		if (numerator) // если есть дробначя часть
		{
			if (integer)cout << "("; //выводим целю часть
			cout << numerator << "/" << denominator;//вываодим дробную часть через дробь
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;//если нет ни целой ни дробной части выводим ноль
			cout << endl;

	}

};

//перегружаем класс Fraction за классом
//оператор умножения
Fraction operator*(Fraction left, Fraction right) // передача по занчению
{
	left.to_improper(); //объекты скопируются в функцию
	right.to_improper();
	
	Fraction result; //создаем объект в котором сохраняем результат
	result.set_numerator(left.get_numerator() * right.get_numerator());
	
//==========эта часть кода выдает ошибку =============================================
	/*Fraction result
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	).to_proper();*/
	result.to_proper().reduce();
	return result;
	
	//==========эта часть кода выдает ошибку =========================================
	
	/*вариант - в return создается временный безымянный объект типа Fraction
	временные бызымянные обекты - существуют в пределах одного выражения 
	и удаляются из памяти по завершении выражеиня*/
	/*return Fraction
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	).to_proper().reduce();*/

}

//перегрузка в классе. оператор деления. список принимаемых параметров
//  и тим возвращаемого значениятот же.

Fraction operator/(const Fraction& left, const Fraction& right) 
{
//==========эта часть кода выдает ошибку =========================================
	/*left.to_improper();
	right.to_improper();
	
	return Fraction
	(
		left.get_numerator()*right.get_denominator()
		right.get_numerator()*left.get_denominator()
	).to_proper();*/
	return left * right.inverted();
}

//#define CONSTRUCTORS_CHECK
//#define ARIFMETICL_OPERATORS_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK

	int a;
	Fraction A;//Default constructor конструктор по умолчанию
	// Fraction - тип данных А - объект то есть создается объект Fraction
	// объекты класса создает конструктор по умолчанию (может быть вызван без параметров)
	A.print(); 

	Fraction B = 5; //конструктор с одним параметром
	B.print();

	Fraction C(1, 2); //конструктор с двумя параметрами
	C.print();

	Fraction D(2, 3, 4);
	D.print();

#endif // CONSTRUCTORS_CHECK
	
#ifdef ARIFMETICL_OPERATORS_CHECK



	//объявление операндов
	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

  /*double a = 2;
	double b = 5;
	double c = a * b;

	Fraction C = A * B; //оператор умножения вывод на экрат
	A.print();
	B.print();
	C.print();

	Fraction D = A / B;
	D.print();*/
	A *= B;
	A.print();

	A /= B;
	A.print();
#endif // ARIFMETICL_OPERATORS_CHECK

	for (double i = 0.5; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;

	for (Fraction i(1, 2); i.get_integer() < 10; i++)
	{
		i.print();
	}
}