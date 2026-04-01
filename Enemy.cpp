#include "Enemy.h"
#include <iostream>
#include <string>

using namespace std;
int Enemy::countEnemy = 0;
ostream& operator<<(ostream &os, const Enemy &enemy)
{
    os << "Name: " << enemy.name
       << "\nType: " << enemy.type
       << "\nDamage: " << enemy.damage
       << "\nHealth: " << enemy.health;
    return os;
}
Enemy::Enemy(string Inpname, string Inptype, int Inpdamage, int Inphealth)
    :name{Inpname}, type{Inptype}, damage{Inpdamage}, health{Inphealth}
{
    cout << "Enemy created: " << name << endl;
    countEnemy++;
}
Enemy::~Enemy()
{
    cout << "Enemy deleted" << endl;
    countEnemy--;
}
