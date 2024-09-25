#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    srand(time(NULL));

    int answer = rand() % 100;//정답
    int tries = 0;//시도 횟수

    int guess;

    while (1)
    {
        tries++;
        cout << "정답을 추측하여 보시오:";
        cin >> guess;
        if (answer == guess)
        {
            break;
        }
        else if (answer > guess)
        {
            cout << "제시한 정수가 낮습니다." << endl;
        }
        else
        {
            cout << "제시한 정수가 높습니다." << endl;
        }
    }
    cout << "축하합니다. 시도 횟수=" << tries << endl;
    return 0;
}