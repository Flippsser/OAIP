#include <iostream>
using namespace std;
void main()
{
	double t, u, k = 4, a = 4.1, x = 5e-5;
	t = 2 * tan(k) / a + log(3 + x) + exp(x);
	u = sqrt(t + 1) - sin(x) * cos(t);
	printf("t=%f",t);
	
	printf("\nu=%f",u);
	
}
