#include <iostream>
using namespace std;
int main()
{
	char s[256];
	int i=0;
	puts("Enter string: ");
	gets_s(s);
	for (i = 0; s[i] != 0; i++)
	{
		if (s[i] == '*') {
			i++;
			for (i ; s[i] != 0; i++)
			{
				if (s[i] == '*') {
					return 0;
				}
				cout << s[i];

			}
		}
	}	  
}
