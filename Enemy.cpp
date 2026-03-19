#include "Enemy.h"
#include <iostream>
#include <string>

using namespace std;
Enemy::Enemy(string Inpname, string Inptype, int Inpdamage)
    :name{Inpname}, type{Inptype}, damage{Inpdamage} {
    cout << "Enemy created: " << name << endl;
}
Enemy::~Enemy() {
    cout << "Enemy deleted" << endl;
}
