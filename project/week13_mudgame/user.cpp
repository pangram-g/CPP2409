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
    os << "���� HP�� " << user.health << " �̰�, ���� �������� �� " << user.itemCnt << " �� �Դϴ�" << endl;
    return os;
}

/*void User::DoAttack()
{
    cout << "�����մϴ�" << endl;
}*/

void Magician::DoAttack()
{
    cout << "���� ���" << endl;
}

void Warrior::DoAttack()
{
    cout << "���� ���" << endl;
}

void Magician::user_name()
{
    cout << "������";
}

void Warrior::user_name()
{
    cout << "����";
}