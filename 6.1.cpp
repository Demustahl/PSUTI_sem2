#include "header.h"
#include "rational.h"

inline void comparison(bool v)
{
	if (v)
		cout << "Верно" << endl;
	else
		cout << "Неверно" << endl;
}

int main()
{
	setlocale(LC_ALL, "");

	Rational r1(25, 15), r2(35), r3(5.6);

	comparison(r1 == r3);
	comparison(r1 != r2);
	comparison(r2 == 35);
	comparison(r3 >= 5.6);
	comparison(r1 < r3);
	comparison(r2 > r3);
	comparison(r1 <= 0.5);

	return 0;
}