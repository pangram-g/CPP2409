#include "user.h"

User::User() : health(20) {}

void User::InCreaseHP(int inc_hp)
{
    health += inc_hp;
}

void User::DeCreaseHP(int dec_hp)
{
    health -= dec_hp;
}
int User::GetHP()
{
    return health;
}