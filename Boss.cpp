#include "Boss.h"
#include <iostream>

Boss::Boss(string nameInp, int healthInp, string typeInp, int damageInp,
           string ultName, int ultDmg, string ultEff, int armInp)
    : Enemy{nameInp, healthInp, typeInp, damageInp},
      ultimate{ultName, ultDmg, ultEff},
      armor{armInp}
{
    cout << "Boss " << name << " is created with power " << ultEff<< endl;
}

void Boss::specialAttack() {
    cout << name << " Boss throws his power!" << endl;
    ultimate.use();
}

Boss::~Boss() {
    cout << "Boss " << name << " is gone." << endl;
}
