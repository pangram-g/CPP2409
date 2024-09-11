#include <iostream>
using namespace std;

int main()
{
    int x, y; // x,y는 가지고 있는 돈, 사탕의 가격을 입력받음
    cout << "현재 가지고 있는 돈: ";
    cin >> x;
    cout << "캔디의 가격 : ";
    cin >> y;
    int i, k; // i,k는 최대로 살수있는 캔디의 값, 남은돈을 계산하여 저장
    i = x / y;
    k = x % y;
    cout << "최대로 살수있는 캔디 = " << i << endl;
    cout << "캔디 구입후 남은 돈 = " << k << endl;
    return 0;
}