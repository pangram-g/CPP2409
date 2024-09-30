#include <iostream>
#include <string>
using namespace std;

int main()
{
    const int maxPeople = 5;
    string names[maxPeople];
    int ages[maxPeople];

    cout << maxPeople << "명의 회원 정보를 입력해주세요." << endl;

    for (int i = 0; i < maxPeople; i++)
    { // 사람을 입력받는 구문
        cout << "사람" << i + 1 << "의 이름:";
        cin >> names[i];
        cout << "사람" << i + 1 << "의 나이:";
        cin >> ages[i];
    }
    int maxage = ages[0];
    int minage = ages[0];
    for (int i = 0; i < maxPeople; i++)
    { // 가장 많은 나이와 가장 적은 나이를 구하는 구문
        if (maxage <= ages[i])
        {
            maxage = ages[i];
        }
        if (minage >= ages[i])
        {
            minage = ages[i];
        }
    }
    int num;
    while (1)
    { // 선택구문, 나이 많은,적은사람이 여러명일경우 전부출력방식 채택
        cout << "1.가장 나이가 많은 사람 출력" << "\n";
        cout << "2.가장 나이가 적은 사람 출력" << "\n";
        cout << "3.종료" << "\n";
        cin >> num;
        // switch문 방식
        switch (num)
        {
        case 1:
            for (int i = 0; i < maxPeople; i++)
            {
                if (ages[i] == maxage)
                {
                    cout << names[i] << " (" << ages[i] << "세)" << endl;
                }
            }
            break;
        case 2:
            for (int i = 0; i < maxPeople; i++)
            {
                if (ages[i] == minage)
                {
                    cout << names[i] << " (" << ages[i] << "세)" << endl;
                }
            }
            break;
        case 3:
            cout << "프로그램을 종료합니다.";
            return 0;
        default:
            cout << "다른숫자를 입력해셨습니다. 프로그램을 종료합니다.";
            return 0;
        }
    }
}
// if문 방식
/*if(num==1){
    for(int i = 0; i < maxPeople; i++){
        if(ages[i]==maxage){
            cout << names[i] << " (" << ages[i] << "세)" << endl;
        }
    }
}
else if(num==2){
    for(int i = 0; i < maxPeople; i++){
        if(ages[i]==minage){
            cout << names[i] << " (" << ages[i] << "세)" << endl;
        }
    }
}
else if(num==3){
    cout<<"프로그램을 종료합니다.";
    return 0;
}
else{
    cout<<"다른숫자를 입력해셨습니다. 프로그램을 종료합니다.";
    return 0;
}*/