#include <iostream>
using namespace std;

int main()
{
    int x;   // x는 화씨온도를 입력받음
    float y; // y는 주어진 화씨온도로 섭씨온도를 계산함
    cout << "화씨온도: ";
    cin >> x;
    y = (5.0 / 9.0) * (float(x) - 32);
    cout << "섭씨온도 = " << y;
}