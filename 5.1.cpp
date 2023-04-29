#include <iostream>
#include <locale.h>
#include "Mod_int.h"

using namespace std;

void Mod_int::add(int i)
{
	v += i % 60;
}

int main()
{
	setlocale(LC_ALL, "");
	int num;
	cout << "Число: ";
	cin >> num;
	Mod_int int_(num);
	cout << "Какое число добавить по модулю 60: ";
	cin >> num;
	int_.add(num);
	cout << "Результат: ";
	int_.print();
}