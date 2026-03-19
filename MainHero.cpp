#include "MainHero.h"
#include <iostream>
#include <string>
using namespace std;
MainHero::MainHero(string nameInp, int healthInp, int XPInp)
    : name{nameInp}, health{healthInp}, XP{XPInp}
{
    cout << "MainHero with 3 arg created" << endl;
}
MainHero::MainHero(string nameInp)
    : MainHero(nameInp, 100, 0)
{
    cout << "Constructor with 1 argument created" << endl;
}
MainHero::MainHero(string nameInp, int healthInp)
    : MainHero(nameInp, healthInp, 0)
{
    cout << "Constructor with 2 arguments created" << endl;
}

MainHero::MainHero()
    : MainHero("Hero", 100, 0)
{
    cout << "Default MainHero created" << endl;
}
MainHero::~MainHero() {
    cout << "MainHero deleted" << endl;
}
