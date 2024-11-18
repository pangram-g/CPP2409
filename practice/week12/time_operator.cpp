#include <iostream>
using namespace std;

class Time
{
    int hour, min, sec;

public:
    Time(int h = 0, int m = 0, int s = 0) : hour(h), min(m), sec(s) {}
    bool operator==(Time &t2)
    {
        return (hour == t2.hour && min == t2.min && sec == t2.sec);
    }

    bool operator!=(Time &t2)
    {
        return !(*this == t2);
    }
};

int main()
{
    Time t1(1, 2, 3), t2(1, 2, 3);

    // 참, 거짓을 1,0 이아닌 true,false로 출력
    cout.setf(cout.boolalpha);
    cout << (t1 == t2) << endl;
    cout << (t1 != t1) << endl;
    return 0;
}