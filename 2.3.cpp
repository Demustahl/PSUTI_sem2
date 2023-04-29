#include <iostream>
#include <locale.h>
#include <assert.h>

using namespace std;

void check(int u, int l) {
	assert(u - l > 0);
}

int main()
{
	setlocale(LC_ALL, "");
	int lb, ub;
	cout << "Введите нижнюю и верхнюю границу массива: " << endl;
	cin >> ub >> lb;
	check(ub, lb);
	int* din = new int[ub - lb + 1];
	cout << "Стандартный массив: " << endl;
	for (int i = lb, ii = 0; i <= ub; i++, ii++) {
		cout << i << " ";
		din[ii] = i;
	}
	cout << endl << "Динамический массив: " << endl;
	for (int i = 0; i <= ub - lb; i++) {
		cout << din[i] << " ";
	}
	delete[] din;
}