#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> score;
    int i = 0;
    while (1)
    {
        int a=0;
        cout << "성적을 입력하시오(종료는 -1) : ";
        cin >> a;
        if(a==-1)break;
        score.push_back(a);
        i++;
    }
    int sum=0;
    int count=0;
    while (score.empty() != true)
    {
        if (score.back() != -1)
        {
            sum += score.back();
            count++;
        }
        score.pop_back();
    }
    cout << "성적 평균 = " << (sum / count) << endl;
    return 0;
}