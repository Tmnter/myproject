#include "Enemy.h"
#include <iostream>
#include <string>

using namespace std;
int Enemy::countEnemy = 0;
ostream& operator<<(ostream &os, const Enemy &enemy)
{
    os << "Name: " << enemy.name
       << "\nHealth: " << enemy.health
       << "\nType: " << enemy.type
       << "\nDamage: " << enemy.damage
    return os;
}
Enemy::Enemy(string Inpname, int Inphealth, string Inptype, int Inpdamage)
    :Character{Inpname, Inphealth}, type{Inptype}, damage{Inpdamage}
{
    cout << "Enemy created: " << name << endl;
    countEnemy++;
}
Enemy::~Enemy()
{
    cout << "Enemy deleted" << endl;
    countEnemy--;
}
