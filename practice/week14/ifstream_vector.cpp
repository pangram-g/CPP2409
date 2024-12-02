#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Temper
{
public:
    int hour;
    double temperature;
};

int main()
{
    ifstream is{"temp.txt"};
    if (!is)
    {
        cerr << "파일 오픈에 실패하였습니다." << endl;
        exit(1);
    }
    vector<Temper> temp;
    int hour;
    double temperature;

    while (is >> hour >> temperature)
    {
        temp.push_back(Temper{hour, temperature});
    }
    for (Temper t : temp)
    {
        cout << t.hour << "시: 온도 " << t.temperature << endl;
    }
    return 0;
}