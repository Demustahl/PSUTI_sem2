#include "header.h"

using namespace std;

class Person {
private:
  string name;
  unsigned int age;
  string gender;
  string phone_num;

public:
  Person(string n, unsigned int a, string g,
         string p_n) { // объявляем конструктор
    name = n;
    age = a;
    gender = g;
    phone_num = p_n;
  }
  void print() { // функция вывода всех данных
    cout << "Имя: " << name << "\nВозраст: " << age << "\nПол: " << gender
         << "\nНомер телефона: " << phone_num << endl;
  }
  void change_name(string n) { name = n; }
  void change_age(int n) { age = n; }
  void change_gender(string n) { gender = n; }
  void change_phone_num(string n) { phone_num = n; }
};

int _main() {
  setlocale(LC_ALL, "");
  Person maksim("Maksim", 18, "men", "+79179517663");
  string name;
  unsigned int age;
  string gender;
  string phone_num;
  int a;
  string ans;
  cout << "\tВывод данных о человеке по умолчанию: " << endl;
  maksim.print();
  cout << "\n\nВведите имя человека: ";
  cin >> name;
  cout << "Введите возраст: ";
  cin >> age;
  cout << "Введите пол: ";
  cin >> gender;
  cout << "Введите номер телефона: ";
  cin >> phone_num;
  Person pers(name, age, gender, phone_num);
  cout << "\n\tВывод данных о произвольном человеке: " << endl;
  pers.print();
  cout << "Вы хотите изменить какие-то данные?" << endl;
  cout << "0 - нет.\n1 - да." << endl;
  cin >> a;
  if (a) {
    while (1) {
      cout << "Что именно?" << endl;
      cout << "0 - имя.\n1 - возраст.\n2 - пол.\n3 - номер телефона." << endl;
      cin.clear();
      cin >> a;
      switch (a) {
      case 0:
        cout << "Имя: " << endl;
        cin >> ans;
        pers.change_name(ans);
        break;
      case 1:
        cout << "Возраст: " << endl;
        cin >> a;
        pers.change_age(a);
        break;
      case 2:
        cout << "Пол: " << endl;
        cin >> ans;
        pers.change_gender(ans);
        break;
      case 3:
        cout << "Номер телефона: " << endl;
        cin >> ans;
        pers.change_phone_num(ans);
        break;
      }
      cout << "Вы хотите еще изменить какие-то данные?" << endl;
      cout << "1 - нет.\n0 - да." << endl;
      cin.clear();
      cin >> a;
      if (a) {
        break;
      }
    }
  }
  cout << "\tВывод данных о человеке: " << endl;
  pers.print();
}