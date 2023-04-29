#include <iostream>
#include <assert.h>
#include <locale.h> 
#include <fstream>
using namespace std;

int gcd(int m, int n)
{
	int r;
	while ((r = m % n)) m = n, n = r;
	return n;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "");
	int x, y, g;
	fstream dat;
	dat.open(argv[1]);
	fstream ans;
	ans.open(argv[2]);
	if (!dat) {
		cout << "\nФайл dat не открылся(";
		return 1;
	}
	else if (!ans) {
		cout << "\nФайл ans не открылся(";
		return 1;
	}
	ans << "Программа gcd на C++\n";
	do {
		ans << "\nВведите два целых числа (окончание x=y):";
		dat >> x >> y; assert(x * y != 0);
		ans << "\nGCD(" << x << ", " << y << ") = " << (g = gcd(x, y)) << endl;
		assert(x % g == 0 && y % g == 0);
	} while (x != y);
	return 0;
}