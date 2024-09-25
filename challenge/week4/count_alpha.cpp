#include <iostream>
using namespace std;

int main()
{
    int vowel = 0;
    int consonant = 0;
    cout << "영 소문자를 입력하고 ctrl+z를 치세요" << endl;

    char ch;
    while (!cin.eof())
    {
        cin >> ch;
        if (ch >= 65 && ch <= 90)
        {
            cout << "소문자가 아닌 영어입니다" << "\n"
                 << "다시 입력해주세요" << endl;
            continue;
        }
        int i = int(ch);
        switch (i)
        {
        case 97:
        case 101:
        case 105:
        case 111:
        case 117:
            vowel++;
            break;
        default:
            consonant++;
            break;
        }
        ch = '1';
    }
    cout << "모음 : " << vowel << endl;
    cout << "자음 : " << (consonant - 1) << endl;
}