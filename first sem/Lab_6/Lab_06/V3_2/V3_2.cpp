#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  double z, q, j=-1, y = -1.5, a = 6;

  while (j <= 1)
  {
    z = sqrt(a + 1) - tan(j + y);
    q = exp(-j * 0.1 * y) + pow(3 * z, 2);
    cout << "j=" << j << "\t";
    cout << " q=" << q << endl;
   j=j+0.2;
  }
  

}