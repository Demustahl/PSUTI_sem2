#include <locale.h>
#include <iostream>

using namespace std;

void print_struct_dairy(struct dairy* product);
double print_calories(struct dairy* product, int weight);

struct dairy
{
	string title;
	unsigned weight;
	unsigned energy_value;
	unsigned protein;
	unsigned fats;
	unsigned carbohydrates;
};

int main()
{
	setlocale(LC_ALL, "");
	int weight;
	dairy product;
	product.title = "Cheese";
	product.weight = 25;
	product.energy_value = 375;
	product.protein = 5;
	product.fats = 8;
	product.carbohydrates = 0;
	print_struct_dairy(&product);
	cout<<"\nEnter weight: ";
	cin>>weight;
	cout<<"\n"<<product.title<<" weighing "<<weight\
		<<" grams contains "<<print_calories(&product, weight)\
		<<" calories.";
}

void print_struct_dairy(struct dairy* product) {
	cout<<"\t"<<product->title<<" weighing "<<product->weight\
		<<" grams contains:\n"<<product->energy_value\
		<<" calories;\n"<<product->protein<<" grams of proteins;\n"\
		<<product->fats<<" grams of fat;\n"<<product->carbohydrates\
		<<" grams of carbohydrates;"<<endl;
}

double print_calories(struct dairy* product, int weight) {
	double portion = (100 * (double)product->energy_value) / product->weight;
	return (portion * weight) / 100;
}