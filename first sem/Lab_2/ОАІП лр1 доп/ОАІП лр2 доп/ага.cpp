#include <iostream>



using namespace std;

int main()
{

    {
        float X, Y, Z, A, B, C;
        X = Y = Z = A = B = C = 0;
        std:: cin >> X;
        std::cin >> Y;
        std::cin >> Z;

        A = X + Y + Z;
        B = X * Y * Z;
        if (A == B)
        {
            cout << "=" << endl;
        }
        
        if (A > B)
        {
            C = A * 3;
            std::cout << C << endl;
        }

        if (A < B)
        {
            C = B * 3;
            std::cout << C << endl;
        }



    }

    return 0;

}



