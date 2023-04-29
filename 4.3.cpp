#include <iostream>
#include <locale.h>
#include "Deque.h"

using namespace std;

bool Deque::relocate()
{
    char copy[max_len];
    int offset, count = 0, f = 0;
    if (!check_not_full_top() && !check_not_full_bottom()) {
        cout << "Массив полностью забит сверху и снизу, перемещать массив некуда(" << endl;
        return false;
    }
    else if (!check_not_full_top()) {
        if ((max_len - bottom) % 2) offset = ((max_len - bottom) / 2) + 1;
        else offset = (max_len - bottom) / 2;
        for (int i = 0, ii = offset; i < bottom; i++, ii++) {
            copy[ii] = s[i];
        }
        for (int i = offset; i < offset + bottom; i++) {
            s[i] = copy[i];
        }
        top += offset; bottom += offset;
        return true;
    }
    else if (!check_not_full_bottom()) {
        if ((top + 1) % 2) offset = ((top + 1) / 2) + 1;
        else {
            f++;
            offset = (top + 1) / 2;
        }
        for (int i = top + 1, ii = offset - f; i < max_len; i++, ii++) {
            copy[ii] = s[i];
        }
        for (int i = top + 1; i < bottom - offset; i++) {
            s[i] = copy[i];
        }
        top -= offset; bottom -= offset;
        return true;
    }
    else {
        cout << "Массив полностью не забит сверху или снизу, перемещать массив незачем." << endl;
        return false;
    }
}

int main()
{
    setlocale(LC_ALL, "");
    Deque deque;
    int br = 0;
    char menu, ch;
    while (1) {
        cout << "\n\n\n\n\tМеню взаимодействия с DEQUE\n\
1 - Обнулить очередь;\n\
2 - Вывести очередь целиком сверху донизу;\n\
3 - Добавить символ на верх очереди;\n\
4 - Добавить символ в низ очереди;\n\
5 - Вывести символ с верха очереди и удалить его;\n\
6 - Вывести символ с низа очереди и удалить его;\n\
7 - Переместить массив в середину (если массив заполнен только сверху или снизу);\n\
8 - Закрыть программу;\n\
--------------------------------\n\n\nВведите нужную цифру" << endl;
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
            if (deque.relocate()) cout << "Перемещение массива прошло успешно)" << endl;
            else cout << "Перемещение массива не удалось(" << endl;
            break;
        case '8':
            br = 1;
            break;
        }
        if (br) break;
        cout << "\n--------------------------------\n" << endl;
    }
}