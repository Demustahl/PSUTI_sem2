#include "header.h"
#include "matrix_iterator.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    Matrix_iterator m1(6, 4);
    m1.full_massiv();
    cout << "Максимальное значение в массиве: " << m1.found_max() << endl;
    return 0;
}