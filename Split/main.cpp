#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()

{
	setlocale(LC_ALL, "");

	const int n = 10;
	int arr[n];
	FillRand(arr, n);
	Print(arr, n);

	//1вычисляем размер массивов
	int even_count = 0;
	int odd_count = 0;
	//перебор всех элементов
	for (int i = 0; i < n; i++)
		//проверка на четность и разбор на массивы по этому признаку
	{
		if (arr[i] % 2 == 0) even_count++;
		else odd_count++;
	}

	//2 выделяем память для четных и нечетных элементов
	int* even_arr = new int[even_count]; // выделяем память для четных элементов
	int* odd_arr = new int[odd_count]; // выделяем память для нечетных элементов

	//3 копируем четные и нечетные элементы в соответствующие массивы
	for (int i = 0, j = 0, k = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0) even_arr[j++] = arr[i]; // если элемент массива четное число копируем его в even_arr
		else odd_arr[k++] = arr[i]; /// если элемент массива нечетное число копируем его в even_arr
	}

	//4 выводим результаты на экран
	Print(even_arr, even_count);
	Print(odd_arr, odd_count);

	//5удаляем динамические массивы
	delete[] odd_arr;
	delete[] even_arr;

}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";

	}

	cout << endl;
}