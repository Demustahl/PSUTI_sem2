#include <iostream>
#include <locale.h>
#include "Deque.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    Deque deque;
    int br = 0;
    char menu, ch;
    deque.reset();
    while (1) {
        cout << "\n\n\n\n\tМеню взаимодействия с DEQUE\n\
1 - Обнулить очередь;\n\
2 - Вывести очередь целиком сверху донизу;\n\
3 - Добавить символ на верх очереди;\n\
4 - Добавить символ в низ очереди;\n\
5 - Вывести символ с верха очереди и удалить его;\n\
6 - Вывести символ с низа очереди и удалить его;\n\
7 - Закрыть программу;\n\
--------------------------------\nВведите нужную цифру" << endl;
        cin >> menu;
        switch (menu) {
        case '1':
            deque.reset();
            cout << "Очередь успешно обнулена." << endl;
            break;
        case '2':
            deque.out_stack();
            break;
        case '3':
            cout << "Какой символ добавить: ";
            cin >> ch;
            deque.push_t(ch);
            break;
        case '4':
            cout << "Какой символ добавить: ";
            cin >> ch;
            deque.push_b(ch);
            break;
        case '5':
            cout << deque.pop_t();
            break;
        case '6':
            cout << deque.pop_b();
            break;
        case '7':
            br = 1;
            break;
        }
        if (br) break;
        cout << "\n--------------------------------\n" << endl;
    }
}