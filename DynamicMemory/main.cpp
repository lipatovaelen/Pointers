#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

int* push_back(int arr[], int& n, int value);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);
	
	
	int value;
	cout << "ВВедите добавленое значение: "; cin >> value;
	// Сщздаем буферный массив нужного размера
	arr = push_back(arr, n, value);
	
	Print(arr, n);

	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//Обращение к элементам массива через оператор индексирования:
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//Обращение к элементам массива через Арифметику указателей и оператор разыменования
		cout << *(arr + i) << "\t";
	}
	cout << endl;
}

int* push_back(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1];
	//2 
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	//3

	delete[] arr;

	arr = buffer;
	//4
	arr[n] = value;
	//5
	n++;

	//6
	return arr;

}