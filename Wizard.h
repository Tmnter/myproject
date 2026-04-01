#ifndef MAGE_H
#define MAGE_H

#include "MainHero.h"
#include <string>

using namespace std;

class Mage : public MainHero {
private:
    int mana;
    string magicSchool;

public:
    Mage(string nameInp = "Gandalf", int healthInp = 80, int xpInp = 0,
         int powerInp = 10, int manaInp = 100, string schoolInp = "Arcane");

    void castSpell();
    ~Mage();
};

#endif
