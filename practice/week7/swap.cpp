#include <iostream>
using namespace std;

void swap(int &x, int &y)//참조자 활용해서 원본데이터도 변경
{
    int tmp;//임시변수
    tmp = x;
    x = y;
    y = tmp;//값 변경
}

int main()
{
    int a = 100, b = 200;

    cout << "a=" << a << "b=" << b << endl;//변경 전

    swap(a, b);

    cout << "a=" << a << "b=" << b << endl;//변경 후
    return 0;
}