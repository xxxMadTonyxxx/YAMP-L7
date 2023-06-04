#include <iostream>
#include <Windows.h>
#include <cmath>
using namespace std;
bool IsCorrect(int begin, int end);
int NumToDigit(int n);

int main()
{
	int end, begin, num, i, Result, ResultArray;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Введите начало интервала: ";
	cin >> begin;
	cout << "Введите конец интервала: ";
	cin >> end;
	if (IsCorrect(begin, end)) {
		cout <<"Некоректно введён интервал \n";
		system("Pause");
		return 0;
	}
	cout << "Введите ваше число: \n";
	cin >> num;
	cout << "Итоговая цифра ввелённого числа: ";
	Result = NumToDigit(num);
	cout << Result;
	cout << "\n";
	int size = end - begin + 1;
	int* Array = new int[size];
	for (i = 0; i < size ; i++) {
		*(Array + i) = begin + i;
	}
	cout << endl << "Числа из интервала, у которых такая же итоговая цифра" << endl;
	for (i = 0; i < size ; i++) {
		ResultArray = NumToDigit(*(Array + i));
		if (Result = ResultArray) {
			cout << " " << *(Array + i) << "(" << ResultArray <<")" << " ";
	}
	}
		delete[]Array;
		Array = NULL;
		return 0;
}
bool IsCorrect(int n1, int n2)
{
	if (n1 > n2 || n1 < 1)
		return true;
	else return false;
}
int NumToDigit(int n)
{
	long int Sum = 0;
	if (n < 0){
		n = -n;
}
	while (n != 0) {
			Sum += n % 10;
			n /= 10;
		};
	for (n = Sum; Sum > 9;    ) {
		Sum = 0;
		while (n != 0) {
			Sum += n % 10;
			n /= 10;
		}
	}
	return Sum;
}