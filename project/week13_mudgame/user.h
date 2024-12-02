#include <iostream>
#include <string>
using namespace std;

class User
{
protected:
    int health;
    int itemCnt;

public:
    User();
    virtual ~User(){}
    virtual void user_name() = 0;
    void InCreaseHP(int inc_hp);
    void DeCreaseHP(int dec_hp);
    void InCreaseItem(int inc_Item);
    void DeCreaseItem(int dec_Item);
    int GetHP();
    int GetItem();
    friend ostream &operator<<(ostream &os, const User &user);
    virtual void DoAttack() = 0;
};

class Magician : public User
{
public:
    Magician();
    void user_name() override;
    void DoAttack() override;
};

class Warrior : public User
{
public:
    Warrior();
    void user_name() override;
    void DoAttack() override;
};

ostream &operator<<(ostream &os, const User &user);