#include <iostream>
#include <cmath>
int main()
{
	double y = 0.956, N = 4.0, a = 0.000005, t, u, s, s1;
	t = 1/sqrt(y)+14*a;
	u = (t+1) / (a+2);
	s1 = N*2/3+ exp(N*(-1))/u;
	s = log(s1);
	std::cout << "t=" << t << "\n";
	std::cout << "u=" << u << "\n";	
	std::cout << "s=" << s << "\n";
	return 0;
}
