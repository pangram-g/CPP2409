#include <iostream>
using namespace std;

int main()
{
    int a, b, c, largest;
    cout << "3개의 정수를 입력하시오 : ";
    // 3개의 정수를 입력하시오 : 라고 하면 같은수가 나올 수 있다
    cin >> a >> b >> c;
    /*조건에 =을 붙여 같은수가 나오더라도 문제가 없도록 고침
    =이 없을경우 a,b가 제일크고 같고, c가 작을때 c가나옴 ex)8,8,7*/
    if (a >= b && a >= c)
        largest = a;
    else if (b >= c)
        largest = b;
    else
        largest = c;

    cout << "가장 큰 정수는 " << largest << endl;
    return 0;
}