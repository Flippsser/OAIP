#include <stdio.h>
#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	char s[256];
	int i, count,prav=0, YorN=0;
	puts("Enter string: ");
	gets_s(s);
	for (count = i = 0; s[i] != 0; i++)
	{
		if (s[i] == '(')  count++;
		if (s[i] == ')')  count--;
	}
	if (!count)
		puts("Ok\n");
	else
		puts("Not Ok\n");
	for (count = i = 0; s[i] != 0; i++)
	{
		if (s[i] == ')') prav--;
		if (prav < 0)
		{
			YorN++;
			break;
		}
		if (s[i] == '(') prav++;
	}
	if (YorN < 0) {
		cout << "скобки расставлены верно";
	}
	else {
		cout << "скобки расставлены не верно";
	}

}
