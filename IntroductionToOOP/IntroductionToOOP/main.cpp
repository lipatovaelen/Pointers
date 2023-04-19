#include<iostream>
using namespace std;

#define delimeter "\n------------------------------\n"

class  Point
{
	

	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}

	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//conctructor
	Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}

	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t" << this << endl;
	}

	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}

	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor: \t " << this << endl;
	}


	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	
	// оператор
	Point& operator =(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}



	//metod

	void print()const
	{
		cout << "X = " << x << "\ty = " << y << endl;
	}

	double distance(Point& other)const //Point other - другой объект другая точка
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;

		double distance = sqrt(x_distance* x_distance + y_distance * y_distance);
		return distance;
	}

	

	
};

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}


//#define STRUCT_POINT
//#define CONSTRSTRUCT_CHEK
//#define DISTANCE_CHECK
//#define ASSIGNMENT_CHEK




void main()
{
	setlocale(LC_ALL, "");

#ifdef STRUCT_POINT
	int a; //объявление переменноцй а типа int
		Point A; //объявление переменноцй А типа Point
				//объявление объекта А структуры Point
				//создание экземпляра А структуры Point
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;
	cout << sizeof(A) << endl; // сколько занимает байт памяти выходит на экран
	Point* pA = &A;
	cout << pA-> x << "\t" << pA->y << endl;

#endif // STRUCT_POINT
	
#ifdef CONSTRSTRUCT_CHEK
	Point A;
	//A.set_x(2);
	//A.set_y(3);
	//cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();

	Point B = 5; //Single - argument constructot
	B.print();

	Point C(2, 3);
	C.print();

	Point D = C; //конструктор копирвоания  new

	Point E;
	E = D;  //оператор присваивания



#endif // CONSTRSTRUCT_CHEK
#ifdef DISTANCE_CHECK



	Point A(2, 3);
	A.print();

	Point B(7, 8);
	B.print();
	cout << "Расстояние от точки А до точки В: " << A.distance(B) << endl;
	cout << delimeter << endl;
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;
	cout << delimeter << endl;
	cout << "Расстояние между точками   A и В: " << distance(A, B) << endl;
	cout << delimeter << endl;
	cout << "Расстояние между точками   B и A: " << distance(B, A) << endl;

#endif // DISTANCE_CHECK
#ifdef ASSIGNMENT_CHEK

	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	cout << delimeter << endl;
	A = B = C = Point(2, 3);
	cout << delimeter << endl;
	A.print();
	B.print();
	C.print();
#endif // ASSIGNMENT_CHEK


	//операторы перегрузка
	/*1 перегрузка только существующдих операторов
	+ перегружается
	++ перегружается
	%% не перегружается
	@ не перегружается
	2, не все иперегружаются
	3, перегруженные сохраняют приоритет
	4, изменить поаведение операторов надо свтроенными типами невозвожно

*/
};