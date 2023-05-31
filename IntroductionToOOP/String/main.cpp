#include<iostream>
using namespace std;

class String; // объявляем класс String перед оператором
String operator+(const String& left, const String& right); // оператор +
class Matrix;

class String
{
	//Строка в языке 'C' - это массив элементов типа 'char', 
	//последний элемент которого всегда содержит ASCII-символ с кодом 0 - '\0'
	//'\0' является признаком конца строки
	int size;		//размер строки в Байтах
	char* str;		//адрес строки в динамической памяти
public:
	int get_size()const //об оператор вывод строки. оператор перегружается за классолм 
	{
		return size;
	}
	const char* get_str()const //для вывода строки  str на экран
	{
		return str;
	}
	 char* get_str()//метод возвращает указатель. указатель - массив.
		 //к элементам массива доступ поулчить можно адресу 0 значениям - разименовать
	{
		return str;
	}

	//				Constructors:
	explicit String(int size = 80)//explicit запрет на неявное преобразование (инт в чар) 
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "Constructor:\t" << this << endl;
	}
	String(const char str[]) //конструктор с одним параметром тип  char задаем массив
	{
		this->size = strlen(str) + 1;	//Поскольку класс хранит размер в Байтах,добавляем +1 нужен для хранения NULL-terminator -
		this->str = new char[size] {};	//Выделяем память под строку
		for (int i = 0; i < size; i++)this->str[i] = str[i];//заполнить строку
		cout << "Constructor:\t" << this << endl; //выв
	}

	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = other.str[i];
		cout << "CopiConstr: " << this << endl;
	}

	String(String&& other)  //move - метод  Shellow copy - поверхностное копирoвоание
	{
		//move - метод  Shellow copyвыполнили поверхностное копирвоание
		this->size = other.size; // присвоить size
		this->str = other.str;   // присвоить str
		//обнуляем другой объект
		other.size = 0;
		other.str = nullptr; // обнуление строки

			cout << "MoveConstructor: \t" << this << endl;
	}

	String& operator=(String&& other)  //move - метод  Shellow copy - поверхностное копирoвоание
	{
		//move - метод  Shellow copyвыполнили поверхностное копирвоание
		delete[] str;
		this->size = other.size; // присвоить size
		this->str = other.str;   // присвоить str
		//обнуляем другой объект
		other.size = 0;
		other.str = nullptr; // обнуление строки

		cout << "MoveConstructor: \t\t" << this << endl;
		return *this;
	}



	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t" << this << endl;
	}

	// Operators секция операто

	
	String& operator=(const String& other) //оператор присваивания возвращает Strin по ссылке &
	{
		/*int a = 2;
		int b = 3;
		a = b;*/ //в этой строке 2 удаляется
		delete[] str;  //удаляем старую память принадлежащую объекту (ы)
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}


	char& operator[](int i) //оператоар [] вернем str[i] значение по индексу
	{
		return str[i];
	}

	char operator[](int i) const //константа 
	{
		return str[i];
	}

	//				Methods:
	void print()const
	{
		cout << "Size: " << size << endl;
		cout << "Str:  " << str << endl;
	}
};

class Matrix {

};


String operator+(const String& left, const String& right) //строка с результатом копируется на место вызова. нужен конструктор копирвоанияч
// оператор плюс . перегружаем за классом. возвращает две строчки типа чар
//Hello +World делает слиние строк =появляется новая строка размера
{
	String cat(left.get_size() + right.get_size() - 1);//создаем новый объект =новая строка от слияния
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
	//cat.get_str()[i] = left.get_str()[i];//доступ к элементам массива квадратные скобки [i] 
	//[i] разименоввыва.т элемент массива. строка =массив к нему применили кв. скобки.
	for (int i = 0; i < right.get_size(); i++)//добавляет к нашей строке вторую строку -конструктор копирвоания
		cat[i + left.get_size() - 1] = right[i];
	//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return cat;//возвращаем cat
}


std::ostream& operator<<(std::ostream& os, const String& obj)
//оператор вывод строки. оператор перегружается за классолм 
//т.к.обычная функция принимает поссыле 
{
	return os << obj.get_str();//взять, 
}

#define HOME_WORK


void main()
{
	setlocale(LC_ALL, "");
	//cout << "Hello String" << endl;//проверочный код
	//String str1;
	//str1.print();

//	String str = "Hello"; 
	//str.print();// конструктор вывод на экран
	//cout << str << endl; //вывод строки. оператор перегружается за классолм т.к.обычная функция

#ifdef HOME_WORK
	String str1 = "Hello";//преобразование из другого (Hello) в наш тип.
	//преобразование выполняет конструктор с одним параметром
	//конструктор с одним параметром тип  char занимает один байт
	cout << str1 << endl;

	String str2 = "World"; //нужен оператор плюс. перегружаем за классом. возвращает две строчки типа чар оператор
	cout << str2 << endl;

	String str3 = str1 + " " + str2; //сopy constructor
	//String str3;
	//str3 = str1 + str2;
	cout << str3 << endl;
	//str1 += str2;
	//cout << str1 << endl;



#endif // HOME_WORK

	//move- методы  - методы переноса
	//move-constructor - конструктор переноса
	//move -Assignmen   -  оператор присваивания переноса

	//move - методы выполняют Shellow copy - поверхностное копирвоание

	//r - value reference   Class && other 

	
	/*неявно вызываются когда создаваемый (существующиц) объект инициализируется 
	значением временного безымянного объекта
	временный бызымянный объект всяыкий раз неявно создается когда функция возвращает
	значение по значению
	в тпаком случае возвращаемое занчение копируетсч на место вызова
	и если возвращаеоме значение является рбъектом то для него вызываетсч конструктор копирования
	если возвоазщаемый объект использует динамичесую память то 
	конструктор попирвоания выделит новые рсурсы и выполнит губокое коипровни е 
		которо е приводит к затратам ресурсов памяти и процесорного времени*/
	/*следует учитывать что на место вызова копируектся локильный объект который
	сейчас же будет удален из памяти
	т.е все эти ресурсвы затрачиваются на копирвание того что спейчас будет удалено
	вместо копирования и удаления локального объекта его динамическую память можно
	просто перенести 	на место вызова пр иэтом ситуация когда два объекта испльзуют одну
	область динам. памчти невозможно т.к. объект сразу же удаляется деструктором.
	методы переноса принимают не константную и не ссылку на объект а так называемую 
	r-value reference   Class&& other
	методы переноса в обязательно порчдке должны очищать(обнулять)  другой объект
	т.к. для него в любом случае будет вызван деструктор
	если не обнулить указатель на динамическую памыть она будет удалена деструктором
	и на месте вызова мы получим мусор.

	*/

	const int n = 5;
	int arr[n] = { 3, 5, 8, 13 };

}