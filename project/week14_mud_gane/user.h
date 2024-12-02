#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class User
{
protected:
    int health;
    int itemCnt;

public:
    User();
    virtual void user_name() = 0;
    virtual void InCreaseHP(int inc_hp);
    virtual void DeCreaseHP(int dec_hp);
    virtual void InCreaseItem(int inc_Item);
    virtual void DeCreaseItem(int dec_Item);
    virtual int GetHP();
    virtual int GetItem();
    friend ostream &operator<<(ostream &os, const User &user);
    virtual void DoAttack() = 0;
};

class Magician : public User
{
public:
    void user_name();
    void DoAttack();
};

class Warrior : public User
{
public:
    void user_name();
    void DoAttack();
};

ostream &operator<<(ostream &os, const User &user);