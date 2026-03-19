#ifndef MAINHERO_H
#define MAINHERO_H
#include "Enemy.h"
#include <string>
#include <iostream>

using namespace std;

class MainHero {
private:
    string name;
    int health;
    int XP;
    int power;

public:
    MainHero& Attack(MainHero &other);
    MainHero(const MainHero &other);
    MainHero(string nameInp, int healthInp, int xpInp, int power);
    MainHero(string nameInp, int healthInp, int xpInp);
    MainHero();
    MainHero(string nameInp);
    MainHero(string nameInp, int healthInp);

    int getXP() { return XP; }
    string getName() { return name; }
    int getHealth() { return health; }
    void setHealth(int h) { if(h >= 0) health = h; }
    ~MainHero();
};

#endif
