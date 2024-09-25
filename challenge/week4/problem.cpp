#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    int i;
    int ans;
    cout << "산수 문제를 자동으로 출제합니다." << endl;

    while (1)
    {
        int firstNum = rand() % 100;
        int secindNum = rand() % 100;
        cout << firstNum << "+" << secindNum << "=";
        cin >> ans;
        if (ans == (firstNum + secindNum))
        {
            cout << "맞았습니다." << endl;
            break;
        }
        else
        {
            cout << "틀렸습니다." << endl;
        }
    }
    return 0;
}