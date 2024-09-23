#include <iostream>
using namespace std;

int main()
{
    int number;
    cout << "숫자를 입력하시오 : ";
    cin >> number;
    switch (number)
    {
    case 0:
        cout << "Zero" << endl;
        break;
    case 1:
        cout << "One" << endl;
        break;
    default:
        cout << "Many" << endl;
        break;
    }

    return 0;
}