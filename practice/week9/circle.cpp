#include <iostream>

using namespace std;

class Circle
{
public:
    double CalcArea();

    int radius;   // 반지름
    string color; // 색상
};

// 클래스 외부에서 클래스 내부의 함수 정의
double Circle::CalcArea()
{
    return 3.14 * radius * radius;
}

int main()
{
    Circle c;
    c.radius = 10;
    cout << c.CalcArea() << endl;
    return 0;
}