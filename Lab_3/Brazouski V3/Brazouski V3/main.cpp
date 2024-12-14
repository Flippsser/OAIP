#include <iostream>

int main()
{
	double i=-6, x=4.5, z=0.0000015,d, f;
	d = tan(x * (-1) * i) / sqrt(x - z);
	f = sin(2*d)/d;
	printf ( "d="  d"\n");
	std::cout << "f=" << f;
	return 0;
}
