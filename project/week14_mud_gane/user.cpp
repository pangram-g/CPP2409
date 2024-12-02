#include "user.h"

User::User() : itemCnt(0), health(20) {}

void User::InCreaseHP(int inc_hp)
{
    health += inc_hp;
}

void User::DeCreaseHP(int dec_hp)
{
    health -= dec_hp;
}
void User::InCreaseItem(int inc_Item)
{
    itemCnt += inc_Item;
}
void User::DeCreaseItem(int dec_Item)
{
    itemCnt -= dec_Item;
}

int User::GetHP()
{
    return health;
}

ostream &operator<<(ostream &os, const User &user)
{
    os << "현재 HP는 " << user.health << " 이고, 먹은 아이템은 총 " << user.itemCnt << " 개 입니다" << endl;
    return os;
}

/*void User::DoAttack()
{
    cout << "공격합니다" << endl;
}*/

void Magician::DoAttack()
{
    cout << "마법 사용" << endl;
}

void Warrior::DoAttack()
{
    cout << "베기 사용" << endl;
}

void Magician::user_name()
{
    cout << "마법사";
}

void Warrior::user_name()
{
    cout << "전사";
}