#include <iostream>
using namespace std;

int main() {
	double a = 1, b = 6, n = 200, h, x = a, s = 0;
	h = (b - a) / n;
	for (x;x < (b - h);x += h) {
		s += h * ((1 + pow(x, 3)) + (1 + pow(x + h, 3)));
		x += h;
	}
	cout << "S=" << s;
}