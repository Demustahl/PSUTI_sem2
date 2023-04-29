#include <iostream>
#include <locale.h>

using namespace std;

char* strrev(char*& s1, const char* s2) {
	s1[strlen(s2)] = '\0';
	for (int i = strlen(s2) - 1, ii = 0;i >= 0; i--, ii++) {
		s1[ii] = s2[i];
	}
	cout << "Стало: " << s1 << endl;
	return s1;
}

int main()
{
	setlocale(LC_ALL, "");
	char* str2 = new char[300];
	cin.get(str2, 300);
	char* str = new char[strlen(str2)+1];
	cout << "Было: " << str2 << endl;
	strrev(str, str2);
	delete [] str;
	delete [] str2;
}