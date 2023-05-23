#include<iostream>
using namespace std;
//�������� ������� ��������� 
class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);

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
	Fraction(int integer, int numerator, int denominator)
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
	// 
	// ���� ����������� �������� ������� ������ �� ������
	Fraction& operator()(int integer, int numerator, int denominator)
	{
		set_numerator(numerator);
		set_integer(integer);
		set_denominator(denominator);
		return *this;
	}

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
	Fraction& operator/=(const Fraction& other)
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
		return inverted;
	}

	//����� ���������� ����� - ���������� ��������� �������
	//more - �������, less-�������, rest-������� �� �������;
	Fraction& reduce()
	{
		int more, less, rest;
		if (numerator > denominator)more = numerator, less = denominator;
		else less = numerator, more = denominator;
		if (less == 0)return *this;
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

	//Fraction result; //������� ������ � ������� ��������� ���������
	//result.set_numerator(left.get_numerator() * right.get_numerator());
	//result.set_denominator(left.get_denominator() * right.get_denominator());

//==========��� ����� ���� ������ ������ =============================================
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
	//result.to_proper().reduce();
	//return result;

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

bool operator==(Fraction left, Fraction right) //�������� �� ���������
{
	left.to_improper(); ����������� ���� � ���� � ������������ �����
		right.to_improper();
	/*if (left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator())
	{
		return true;
	}
	else
	{
		return false;
	}*/
	return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
}

bool operator !=(const Fraction& left, const Fraction& right)
{

	return  !(left == right);
}

bool operator > (Fraction left, Fraction right)
{
	left.to_proper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();

}

bool operator < (Fraction left, Fraction right)
{
	left.to_proper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() <
		right.get_numerator() * left.get_denominator();

}

bool operator (const Fraction& left, const Fraction& right) //������ ��� �����
{

	//return  left > right || left == right; //������ ��� �����
	return !(left < right); // �� ������ (������������)
}

bool operator <=(const Fraction& left, const Fraction& right)
{

	return  !(left > right); // �� ������
}


// ------------ ���������� �������� ����� � ����������
//
std::iostream& operator>>(std::istream& is, Fraction& obj) //����� �� ����� ����������
{
#ifdef INPUT
	int integer, numerator, denominator;
	is >> integer >> numerator, denominator;
	//obj.set_numerator(numerator);
	//obj.set_integer(integer);
	//obj.set_denominator(denominator);
	obj(integer, numerator, denominator);// ���� ����������� �������� ������� ������  
#endif // INPUT

	return is;
}


//#define CONSTRUCTORS_CHECK
//#define ARIFMETICL_OPERATORS_CHECK
//#define INCREMENT_DECREMENT

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

#ifdef INCREMENT_DECREMENT
	for (double i = 0.5; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;

	for (Fraction i(1, 2); i.get_integer() < 10; i++)
	{
		i.print();
	}
#endif // INCREMENT_DECREMENT


	//cout << (Fraction(1, 2) == Fraction(5, 10)) << endl;
	//cout << (Fraction(1, 2) != Fraction(5, 11)) << endl;
	//cout << (Fraction(1, 2) > Fraction(5, 11)) << endl;
	//cout << (Fraction(1, 2) < Fraction(5, 11)) << endl;

	//cout << (Fraction(1, 2) >= Fraction(5, 11)) << endl;
	//cout << (Fraction(1, 4) <= Fraction(5, 10)) << endl;

	//Fraction A; / ����� �� ����� ����������
	//Fraction A(2, 3, 4);
	//cout << A << endl;

	//���� � ���������� ������ �����
	Fraction A;
	cout << "������� ������� �����: "; cin >> A;
	cout << A << endl;



}