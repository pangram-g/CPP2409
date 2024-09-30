#include <iostream>
using namespace std;

int main()
{
    int floor;

    cout << "몇 층을 쌓겠습니까? (5~100): ";
    cin >> floor;

    for (int i = floor; i > 0; i--)
    {//for문 안의 조건식 초기식을 변경
        for (int j = floor - i; j > 0; j--)
        {
            cout << "S";
        }
        for (int k = 2 * i - 1; k > 0; k--)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}