#include <locale.h>
#include <iostream>

using namespace std;

void assign(struct complex* pc, double r, double i);
void print_complex(struct complex* pc);
complex div(struct complex* c, double d);
complex div(double d, struct complex* c);

struct complex
{
	double real;
	double imag;
};

int main()
{
	complex num1, res;
	double c1, c2, d;
	setlocale(LC_ALL, "");
	cout << "Введите действительную и мнимую часть комплексного числа:" \
		<< endl;
	cin >> c1 >> c2;
	assign(&num1, c1, c2);
	cout << "Введите действительное число:" << endl;
	cin >> d;
	cout << "Деление комплексного числа на действительное:" << endl;
	res = div(&num1, d);
	cout << "(";
	print_complex(&num1);
	cout << ") / " << d << " = ";
	print_complex(&res);
	cout << endl;
	cout << "Деление действительного числа на комплексное:" << endl;
	res = div(d, &num1);
	cout << d << " / (";
	print_complex(&num1);
	cout << ") = ";
	print_complex(&res);
	cout << endl;
}

void assign(complex* pc, double r, double i = 0.0)
{
	pc->real = r; pc->imag = i;
}

void print_complex(struct complex* pc)
{
	cout << pc->real;
	if (pc->imag >= 0) {
		cout << "+";
	}
	cout << pc->imag << "i";
}

complex div(struct complex* c, double d)
{
	complex temp;
	temp.real = c->real / d;
	temp.imag = c->imag / d;
	return temp;
}

complex div(double d, struct complex* c)
{
	complex temp;
	temp.real = (d * c->real) / (c->real * c->real + c->imag * c->imag);
	temp.imag = ((-1)*d*c->imag) / (c->real * c->real + c->imag * c->imag);
	return temp;
;}