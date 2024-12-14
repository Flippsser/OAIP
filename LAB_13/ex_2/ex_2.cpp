#include <iostream>
using namespace std;
int main()
{
	char s[256];
	char *ps,*pl,*pj,*pp;
	char l[]{ '0','1','2','3','4','5','6','7','8','9' };
	int i=0,j,p,count=0;
	puts("Enter string: ");
	gets_s(s);
	for (ps = s; *ps != 0; ps++)
	{
		for ( pj = l; *pj != 0; pj++)
		{
			if (*ps == *pj)
			{
				cout << *ps;
				for (pp = s,pl=l; *pp != 0; pp++,pl++)
				{
					if (*pl == *(ps+1)) {
						count++;
						
					}
				}
				if (count != 1) return 0;
				count = 0;
			}
		}
	}
}
