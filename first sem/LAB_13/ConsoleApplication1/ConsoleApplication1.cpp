#include <iostream>
#include <string> 
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    string sentence = "Минск - столица столица Беларуси Беларуси";
    string duplicateWords[15];
    string word;
    int count = 0;
    bool duplicate = true;
    for (int i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] != ' ')
        {
            word += sentence[i];
        }
        else {
            for (int j = 0; j < count; j++)
            {
                if (duplicateWords[j] == word) {
                    duplicate = false;
                    break;
                }
            }
            if (duplicate == true)
            {
                duplicateWords[count] = word;
                count++;
                cout << word << " ";
            }
            word = "";
            duplicate = true;
        }
    }
    return 0;
}