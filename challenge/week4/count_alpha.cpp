#include <iostream>
using namespace std;

int main()
{
    int vowel = 0;
    int consonant = 0;
    cout << "영 소문자를 입력하고 ctrl+z를 치세요" << endl;

    char ch;
    while (!cin.eof())//ctrl+z입력시 끝
    {
        cin >> ch;
        if (ch >= 65 && ch <= 90)
        {//대문자 인식시 다시입력문
            cout << "소문자가 아닌 영어입니다" << "\n"
                 << "다시 입력해주세요" << endl;
            continue;
        }
        int i = int(ch);
        switch (i)
        {//소문자 인식
        case 97:
        case 101:
        case 105:
        case 111:
        case 117:
            vowel++;
            break;
        default://그 외 문자 인식
            consonant++;
            break;
        }
        ch = '1';
    }
    cout << "모음 : " << vowel << endl;
    cout << "자음 : " << (consonant - 1) << endl;//34줄 1도 인식이 되어 -1을 해줌
}