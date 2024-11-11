#include <iostream>
using namespace std;

int main()
{
    int number = 10;
    int *p = &number; //number의 주소를 계산 p에 저장
    cout << *p << endl; //p를 역참조해 가르키는 곳의 값을 출력
    return 0;
}