#include "user.h"

int User::GetHP()
{
    health += 2;
}
void User::InCreaseHP()
{
    health += 2;
}

void User::DeCreaseHP()
{
    health -= 2;
}
int User::GetHP()
{
    return health;
}