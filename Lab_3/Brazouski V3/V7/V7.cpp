#include <iostream>
#include <cmath>
int main()
{
	double m=6, x=1.4, z = 0.0000005, y,w;
	y =  sqrt(1+x) - cos(2/m);
	w = 0.6 * z - 2 * exp((-2) * y * m);
	std::cout << "y=" << y << "\n";
	std::cout << "w=" << w << "\n";
	
	return 0;
}
