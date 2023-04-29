#include <iostream>
#include "Deque.h"

using namespace std;

class Ch_stack {
private:
	char str1[Deque::max_len], str2[Deque::max_len];
	Deque deq;
public:
	Ch_stack(char s1[]) // объ€вл€ем конструктор
	{ 
		for (int i = 0; s1[i] != '\0'; i++)
			str1[i] = s1[i];
		str1[strlen(s1)] = '\0';
		swap(str1, str2);
	}
	void swap(char s1[], char s2[])
	{
		int count = 0;
		for (int i = 0;i < strlen(s1);i++) {
			deq.push_t(s1[i]);
		}
		for (int i = deq.get_top() + 1, ii = 0;i < deq.get_bottom();i++, ii++) {
			s2[ii] = deq.pop_t();
			count++;
		}
		s2[count] = '\0';
	}
	char* getStr()
	{
		return str1;
	}
	char* getSwapStr()
	{
		return str2;
	}
};