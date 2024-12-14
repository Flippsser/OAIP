#include <stdio.h>
#include <cmath>
void main()
{
	double s, p, x[4] = { 8, 1.9, -4, 1 }, a = 105e-4, m = 4, i = 7;
	for (int n = 0; n < 4; n++)
	{
		s = exp(-a * x[n]) - log(i / x[n] * m) / pow(log(m), 2);


		if (s > 2 * x[n])
			p = pow(-i * s, 2);
		else
			p = sin(-6 * x[n]);

		printf("x=%f\t", x[n]);
		printf("p=%5.2f\n", p);
	}

}
