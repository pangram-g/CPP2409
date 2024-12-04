#include <iostream>
using namespace std;

template <typename T1, typename T2>
void copy(T1 a1[], T2 a2[], int n)
{
    // a2에 원소를 a1에 넣음(복사)
    for (int i = 0; i < n; ++i)
        a1[i] = a2[i];
}
int main()
{
    int intArray1[5] = {10, 20, 30, 40, 50};
    double doubleArray2[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    // double를 int에 복사
    copy(intArray1, doubleArray2, 5);

    cout << "Copied intArray1 from doubleArray2 : ";
    for (int i = 0; i < 5; ++i)
    {
        std::cout << intArray1[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}