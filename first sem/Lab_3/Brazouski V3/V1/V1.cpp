#include <iostream>
#include <cmath>
int main()
{
	double  a= 8.1, k = 4.0, x = 0.0002, t, u;
	t = 2*k / a + log(2+x);
	u = sqrt(k-1)/(t + 1) ;
	
	std::cout << "t=" << t << "\n";
	std::cout << "u=" << u << "\n";

	return 0;
}
