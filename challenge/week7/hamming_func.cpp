#include <iostream>
#include <string>
using namespace std;

string toLowerStr(string &str) // 소문자 변경
{
    for (int i = 0; i < str.length(); i++)
    {
        if ('A' <= str[i] && 'Z' >= str[i])
        {
            str[i] += 32;
        }
    }
    return str;
}

string toUpperStr(string &str) // 대문자 변경
{
    for (int i = 0; i <= str.length(); i++)
    {
        if ('a' <= str[i] && 'z' >= str[i])
        {
            str[i] -= 32;
        }
    }
    return str;
}

int calcHammingDist(string &s1, string &s2)
{
    // 대소문자를 맞춰줌
    toLowerStr(s1);
    toLowerStr(s2);
    int difcount = 0;

    // 문자열 다른지 확인
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] != s2[i])
            difcount += 1;
    }
    return difcount;
}

int main()
{
    string s1, s2;
    int check = 1;

    while (check == 1) // 반복문으로 길이가 다르면 다시 하게함
    {
        cout << "DNA1: ";
        cin >> s1;
        cout << "DNA2: ";
        cin >> s2;

        if (s1.length() != s2.length())
            cout << "오류: 길이가 다름" << endl;
        else
        {
            int count = calcHammingDist(s1, s2);
            cout << "해밍 거리는 " << count << endl;
            check = 0;
        }
    }
    return 0;
}