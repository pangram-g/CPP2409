#include <iostream>
#include <string>
using namespace std;

class User
{
private:
    int health;
    int itemCnt;

public:
    User();
    void InCreaseHP(int inc_hp);
    void DeCreaseHP(int dec_hp);
    void InCreaseItem(int inc_Item);
    void DeCreaseItem(int dec_Item);
    int GetHP();
    int GetItem();
    friend ostream &operator<<(ostream &os, const User &user);
};
ostream &operator<<(ostream &os, const User &user);