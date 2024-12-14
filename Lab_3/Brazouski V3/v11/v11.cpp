#include <iostream>
#include <cmath>
int main()
{
	double x=-1.8, a=1.5, z = 0.000000015, w ,d;
	w= tan(1)*(1+x)+z- exp(a);
	d = 9 * sqrt(2 - 3 * x) + abs(a + 1);
	std::cout << "w=" << w << "\n";
	std::cout << "d=" << d << "\n";

	return 0;
}
