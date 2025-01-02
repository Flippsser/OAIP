#include <iostream>
using namespace std;

int main() {
	double a = 0, b = 1, e = 1e-4, x = 0;
	while (abs(a - b) > 2 * e) {
		x = (a + b) / 2;
		if (((pow(x, 2) + 2 * x - 1) * (pow(a, 2) + 2 * a - 1)) <= 0) {
			b = x;
		}
		else {
			a = x;
		}
	}
	cout << x;
}