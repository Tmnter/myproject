#ifndef BOSS_H
#define BOSS_H

#include "Enemy.h"
#include "Superpower.h"
#include <string>
#include <iostream>
using namespace std;
class Boss : public Enemy
{
private:
    Superpower ultimate;
    int armor;

public:
    Boss(string nameInp, int healthInp, string typeInp, int damageInp,
         string ultName, int ultDmg, string ultEff, int armInp);

    void specialAttack();
    virtual ~Boss();
};

#endif
