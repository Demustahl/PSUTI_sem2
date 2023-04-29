#include <iostream>
#include <locale.h>
#include "Ch_stack.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    char str[Deque::max_len];
    cout << "Введите строку которую хотите обратить:" << endl;
    cin.get(str, Deque::max_len);
    Ch_stack ch_stack(str);
    cout << "Результат:" << endl;
    cout << ch_stack.getSwapStr() << endl;
}