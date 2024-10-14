#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s = "Hello, World!";//문자열 객체 생성

    //특정 인덱스의 문자 접급(읽기 전용)
    char ch = s[7];
    cout << "인덱스 7의 문자: " << ch << endl;

    //문자열이 비었는지 확인
    if (!s.empty())
    {
        cout << "문자열은 비어있지 않습니다." << endl;
    }
    else
    {
        cout << "문자열은 비어있습니다." << endl;
    }

    //문자열에 문자열 삽입
    s.insert(5, " C++");
    cout << "index 5에  C++ 문자열 삽입: " << s << endl;

    return 0;
}