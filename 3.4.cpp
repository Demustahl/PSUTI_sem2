#include <locale.h>
#include <iostream>
#include <conio.h>

using namespace std;

const int max_len = 12;

struct ch_deque
{
	char s[max_len];
	int bottom, top;
};

void reset(ch_deque* deq)
{
	deq->top = deq->bottom = max_len / 2;
	deq->top--;
}

int check_not_empty(ch_deque* deq)
{
	if (deq->bottom - deq->top >= 2) {
		return 1;
	}
	else {
		cout << "\nОШИБКА —> Контейнер пуст." << endl;
		return 0;
	}
}

int check_not_full_top(ch_deque* deq)
{
	if (deq->top >= 0) {
		return 1;
	}
	else {
		cout << "\nОШИБКА —> Контейнер переполнен сверху." << endl;
		return 0;
	}
}

int check_not_full_bottom(ch_deque* deq)
{
	if (deq->bottom <= max_len) {
		return 1;
	}
	else {
		cout << "\nОШИБКА —> Контейнер переполнен снизу." << endl;
		return 0;
	}
}

void push_t(ch_deque* deq, char c)
{
	if (check_not_full_top(deq)) {
		deq->s[deq->top] = c;
		deq->top--;
		cout << "Успешно!" << endl;
	}
}

void push_b(ch_deque* deq, char c)
{
	if (check_not_full_bottom(deq)) {
		deq->s[deq->bottom] = c;
		deq->bottom++;
		cout << "Успешно!" << endl;
	}
}

char pop_t(ch_deque* deq)
{
	if (check_not_empty(deq)) {
		deq->top++;
		cout << "Успешно!" << endl;
		return deq->s[deq->top];
	}
}

char pop_b(ch_deque* deq)
{
	if (check_not_empty(deq)) {
		deq->bottom--;
		cout << "Успешно!" << endl;
		return deq->s[deq->bottom];
	}
}

void out_stack(ch_deque* deq)
{
	if (check_not_empty(deq)) {
		cout << "\nВывод очереди сверху донизу:" << endl;
		for (int i = deq->top + 1;i < deq->bottom;i++) {
			cout << deq->s[i] << " ";
		}
		cout << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "");
	ch_deque deque;
	int br = 0;
	char menu, ch;
	reset(&deque);
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
			reset(&deque);
			cout << "Очередь успешно обнулена." << endl;
			break;
		case '2':
			out_stack(&deque);
			break;
		case '3':
			cout << "Какой символ добавить: ";
			cin >> ch;
			push_t(&deque, ch);
			break;
		case '4':
			cout << "Какой символ добавить: ";
			cin >> ch;
			push_b(&deque, ch);
			break;
		case '5':
			cout << pop_t(&deque);
			break;
		case '6':
			cout << pop_b(&deque);
			break;
		case '7':
			br = 1;
			break;
		}
		if (br) break;
		cout << "\n--------------------------------\n" << endl;
	}
}