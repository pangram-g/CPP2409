#include "car.h"
using namespace std;

int main(){
    Car myCar;

    myCar.setSpeed(80);
    cout<<"현재속도는 ";
    cout<<myCar.getSpeed();

    return 0;
}
