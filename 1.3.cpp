#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	int i = 3, * j = &i;
	bool flag = true;
	double x = 1.5;
	cout << "Hello World!" << endl;
	cout << "Целое число int: " << i << endl <<
		"Указатель j на int i:" << endl <<
		"\tадрес: " << j << " или так " << & i << endl <<
		"\tзначение: " << * j << endl <<
		"Логическая переменная flag: " << flag <<
		endl <<
		"Число с плавающей точкой x: " << x << endl
		<< endl <<
		"Теперь попробуем привести эти типы к другим с помощью (int) и (double): " << endl <<
		"(int):" << endl <<
		"\t(int)int: " <<(int)i << endl <<
		"\t(int)int*: " <<(int)j << endl <<
		"\t(int)bool: " <<(int)flag << endl <<
		"\t(int)double: " <<(int)x << endl <<
		"(double):" << endl <<
		"\t(double)int: " <<(double)i << endl <<
		"\t(double)int*: " << (double)*j << endl <<
		"\t(double)bool: " <<(double)flag << endl <<
		"\t(double)double: " <<(double)x << endl <<
		"static_cast<int>:" << endl <<
		"\tstatic_cast<int>int: " << static_cast<int>(i) << endl <<
		"\tstatic_cast<int>int*: " << static_cast<int>(*j) << endl <<
		"\tstatic_cast<int>bool: " << static_cast<int>(flag) << endl <<
		"\tstatic_cast<int>double: " << static_cast<int>(x) << endl <<
		"static_cast<double>:" << endl <<
		"\tstatic_cast<double>int: " << static_cast<double>(i) << endl <<
		"\tstatic_cast<double>int*: " << static_cast<double>(*j) << endl <<
		"\tstatic_cast<double>bool: " << static_cast<double>(flag) << endl <<
		"\tstatic_cast<double>double: " << static_cast<double>(x) << endl;
}