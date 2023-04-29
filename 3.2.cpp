#include <locale.h>
#include <iostream>

using namespace std;

void assign(struct complex* pc, double r, double i);
void print_complex(struct complex* pc);
complex add(struct complex* a, struct complex* b);
complex sub(struct complex* a, struct complex* b);

struct complex
{
	double real;
	double imag;
};

int main()
{
	complex num1, num2, res;
	double c1, c2;
	setlocale(LC_ALL, "");
	cout << "Введите действительную и мнимую часть первого числа:" << endl;
	cin >> c1 >> c2;
	assign(&num1, c1, c2);
	cout << "Введите действительную и мнимую часть второго числа:" << endl;
	cin >> c1 >> c2;
	assign(&num2, c1, c2);
	cout << "Сложение:" << endl;
	res = add(&num1, &num2);
	print_complex(&num1);
	cout << " + ";
	print_complex(&num2);
	cout << " = ";
	print_complex(&res);
	cout << endl;
	cout << "Вычитание:" << endl;
	res = sub(&num1, &num2);
	print_complex(&num1);
	cout << " - ";
	print_complex(&num2);
	cout << " = ";
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

complex add(complex *a, complex *b)
{
	complex temp;
	temp.real = a->real + b->real;
	temp.imag = a->imag + b->imag;
	return temp;
}

complex sub(complex *a, complex *b)
{
	complex temp;
	temp.real = a->real - b->real;
	temp.imag = a->imag - b->imag;
	return temp;
}