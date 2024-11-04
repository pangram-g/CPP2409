#include<iostream>
#include<string>
using namespace std;

class User{
    private:
    int health;
    public:
    User(int sethp){
        health = sethp;
    };
    void InCreaseHP(int inc_hp);
    void DeCreaseHP(int dec_hp);
    int GetHP();
};