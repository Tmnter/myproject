#ifndef CHARACTERS1_H
#define CHARACTERS1_H
#include <string>
#include <iostream>

using namespace std;

class MainHero {
private:
    string name;
    int health;
    int XP;

public:
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
