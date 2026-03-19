#include "MainHero.h"
#include <iostream>
#include <string>
using namespace std;
MainHero& MainHero::Attack(MainHero &other) {
    other.health -= this->power;
    cout << this->name + "attack" + other.name << endl;
    return *this;
}
MainHero::MainHero(const MainHero &other)
: name(other.name), health(other.health), XP(other.XP), power(other.power) {
cout << "Copy constructor called for " + other.name << endl;
}
MainHero::MainHero(string nameInp, int healthInp, int XPInp, int powerInp)
    : name{nameInp}, health{healthInp}, XP{XPInp}, power(powerInp)
{
    cout << "MainHero with 4 arg created" << endl;
}
MainHero::MainHero(string nameInp, int healthInp, int XPInp)
    : MainHero(nameInp, healthInp, XPInp, 0)
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
    : MainHero("Hero", 100, 0, 10)
{
    cout << "Default MainHero created" << endl;
}
MainHero::~MainHero() {
    cout << "MainHero deleted" << endl;
}
