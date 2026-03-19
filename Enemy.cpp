#include "Enemy.h"
#include <iostream>
#include <string>

using namespace std;
int Enemy::countEnemy = 0;
ostream& operator<<(ostream &os, const Enemy &enemy) {
    os << "Name: " << enemy.name
       << " Type: " << enemy.type
       << " Damage: " << enemy.damage;
    return os;
}
Enemy::Enemy(string Inpname, string Inptype, int Inpdamage)
    :name{Inpname}, type{Inptype}, damage{Inpdamage} {
    cout << "Enemy created: " << name << endl;
    countEnemy++;
}
Enemy::~Enemy() {
    cout << "Enemy deleted" << endl;
    countEnemy--;
}
