#include "Mage.h"
#include <iostream>

using namespace std;

Mage::Mage(string nameInp, int healthInp, int xpInp, int powerInp, int manaInp, string schoolInp)
    : MainHero{nameInp, healthInp, xpInp, powerInp},
      mana{manaInp},
      magicSchool{schoolInp}
{
    cout << "Mage from " << magicSchool << " school created!" << endl;
}
void Mage::castSpell()
{
    if (mana >= 10)
    {
        mana -= 10;
        cout << name << " casts magic! Mana left: " << mana << endl;
    }
    else
    {
        cout << name << " doesn't have enough mana (need 10)!" << endl;
    }
}

Mage::~Mage()
{
    cout << "Mage " << name << " disappeared in a cloud of smoke." << endl;
}
