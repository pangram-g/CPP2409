#include <iostream>
using namespace std;

class A
{
public:
    friend class B; // B를 A의 프렌드로
    A(string s = "") : secret{s} {}

private:
    string secret; // B는 A의 프렌드 이므로 접근 가능
};
class B
{
public:
    B() {}
    void print(A obj)
    {
        cout << obj.secret << endl;
    }
};

int main()
{
    A a("이것은 기밀 정보 입니다.");
    B b;
    b.print(a);

    return 0;
}