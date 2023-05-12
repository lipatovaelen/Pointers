#include<iostream>
using namespace std;
//�������� ������� ��������� 
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

  // ������������=======================================================

	Fraction() //Default constructor ����������� �� ��������� -----------------
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstruct:\t" << this << endl;
	}
	Fraction(int integer) //����������� � ����� ����������----------------
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		
	}
	Fraction(int numerator, int denominator) //����������� � ����� �����������
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);//����� � ����������� �� ����� ���� ���������� ������
	}

	//������������� ����������� --------------------------------
	Fraction(int integer, int numerator, int dedenominator = 1)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}

	// ����������� �����������
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

	//������ ���������==================================
	//�������� ������������
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	//�������� ��������*��������� ��� ����������
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}

	//�������� ���������/��������� ��� ����������
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this / other;
	}

	//���������� ��������� ���������/���������
	Fraction& operator++()//���������� ��������� ���������� ++1
	{
		to_proper();
		integer++;
		return *this;
	}
	Fraction& operator++(int)//����������� ��������� ���������� 1++
	{
		//������ ��������� ���� � ������ ���� �������� ���� (int)
		//��� ��������� ����������� �� ������ ���������� ������� ��������
		//����������� ��������� �� �����������
		//��������� ����������� ����� ������ ����������� ����� ���������
		to_proper();
		Fraction old = *this;
		integer++;
		return old;
	}


	// ������ ������: ===================================
	// ����� ������� ���������� ����� � ������������ - ������������ ��������� �������------------
	Fraction& to_improper()
	{
		numerator += integer * denominator; 
		integer = 0; //��������, 
		return *this; //
	}
	// ����� ������� ������������  ����� � ���������� - ������������ ��������� �������------------
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this; //
	}
	//����� "���������" ����� - ��������� � ����������� �������� �������
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		inverted.numerator ^= inverted.denominator;
		inverted.denominator ^= inverted.numerator;
		inverted.numerator ^= inverted.denominator;
	}

	//����� ���������� ����� - ���������� ��������� �������
	//more - �������, less-�������, rest-������� �� �������;
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
		int GCD = more;//���������� ����� ��������
		numerator /= GCD;
		denominator /= GCD;
		return *this;
		
	}

	// ����� ������ ����� �� �����-----------
	void print()const
	{
		if (integer)cout << integer; // ���� ������ ����� �����, ������� ��
		if (numerator) // ���� ���� �������� �����
		{
			if (integer)cout << "("; //������� ���� �����
			cout << numerator << "/" << denominator;//�������� ������� ����� ����� �����
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;//���� ��� �� ����� �� ������� ����� ������� ����
			cout << endl;

	}

};

//����������� ����� Fraction �� �������
//�������� ���������
Fraction operator*(Fraction left, Fraction right) // �������� �� ��������
{
	left.to_improper(); //������� ����������� � �������
	right.to_improper();
	
	Fraction result; //������� ������ � ������� ��������� ���������
	result.set_numerator(left.get_numerator() * right.get_numerator());
	
//==========��� ����� ���� ������ ������ =============================================
	/*Fraction result
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	).to_proper();*/
	result.to_proper().reduce();
	return result;
	
	//==========��� ����� ���� ������ ������ =========================================
	
	/*������� - � return ��������� ��������� ���������� ������ ���� Fraction
	��������� ���������� ������ - ���������� � �������� ������ ��������� 
	� ��������� �� ������ �� ���������� ���������*/
	/*return Fraction
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	).to_proper().reduce();*/

}

//���������� � ������. �������� �������. ������ ����������� ����������
//  � ��� ������������� ����������� ��.

Fraction operator/(const Fraction& left, const Fraction& right) 
{
//==========��� ����� ���� ������ ������ =========================================
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
	Fraction A;//Default constructor ����������� �� ���������
	// Fraction - ��� ������ � - ������ �� ���� ��������� ������ Fraction
	// ������� ������ ������� ����������� �� ��������� (����� ���� ������ ��� ����������)
	A.print(); 

	Fraction B = 5; //����������� � ����� ����������
	B.print();

	Fraction C(1, 2); //����������� � ����� �����������
	C.print();

	Fraction D(2, 3, 4);
	D.print();

#endif // CONSTRUCTORS_CHECK
	
#ifdef ARIFMETICL_OPERATORS_CHECK



	//���������� ���������
	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

  /*double a = 2;
	double b = 5;
	double c = a * b;

	Fraction C = A * B; //�������� ��������� ����� �� �����
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