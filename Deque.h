#include <iostream>

using namespace std;

class Deque {
public:
    static const int max_len = 100;
    Deque()
    { // объявляем конструктор
        reset();
    }
    void reset()
    {
        top = bottom = max_len / 2;
        top--;
    }
    int check_not_empty()
    {
        if (bottom - top >= 2) {
            return 1;
        }
        else {
            cout << "\nКонтейнер пуст." << endl;
            return 0;
        }
    }
    int check_not_full_top()
    {
        if (top >= 0) {
            return 1;
        }
        else {
            if (relocate(1)) {
                return 1;
            }
            else {
                return 0;
            }
        }
    }
    int check_not_full_bottom()
    {
        if (bottom < max_len) {
            return 1;
        }
        else {
            if (relocate(0)) {
                return 1;
            }
            else {
                return 0;
            }
        }
    }
    void push_t(char c)
    {
        if (check_not_full_top()) {
            s[top] = c;
            top--;
        }
    }
    void push_b(char c)
    {
        if (check_not_full_bottom()) {
            s[bottom] = c;
            bottom++;
        }
    }
    char pop_t()
    {
        if (check_not_empty()) {
            top++;
            return s[top];
        }
    }
    char pop_b()
    {
        if (check_not_empty()) {
            bottom--;
            return s[bottom];
        }
    }
    void out_stack()
    {
        if (check_not_empty()) {
            cout << "\nВывод очереди сверху донизу:" << endl;
            for (int i = top + 1;i < bottom;i++) {
                cout << s[i] << " ";
            }
            cout << endl;
        }
    }
    bool relocate(int what)
    {
        char copy[max_len];
        int offset, count = 0, f = 0;
        if ((top == -1) && (bottom == max_len)) {
            cout << "Очередь заполнена сверху и снизу!";
            return false;
        }
        else {
            if (what) {
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
            else if (!what) {
                if ((top + 1) % 2) offset = ((top + 1) / 2) + 1;
                else {
                    f++;
                    offset = (top + 1) / 2;
                }
                for (int i = top + 1, ii = top - offset + 1; i < max_len; i++, ii++) {
                    copy[ii] = s[i];
                }
                for (int i = top - offset + 1; i < bottom - offset; i++) {
                    s[i] = copy[i];
                }
                top -= offset; bottom -= offset;
                return true;
            }
        }
    }
    int get_top() {
        return top;
    }
    int get_bottom() {
        return bottom;
    }
private:
    char s[max_len];
    int top, bottom;
};