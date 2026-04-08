#include "Villager.h"
#include <iostream>
#include <string>

using namespace std;
Villager::Villager(Villager&& other)
    : Character{move(other)}, job{move(other.job)}
{
    this->money = other.money;
    other.money = nullptr;
    cout << "Move constructor called"<< endl;
}
Villager::Villager(const Villager &other)
    : Character{other}, job{other.job}
{
    money = new int;
    *money = *other.money;
    cout << "Deep copy constructor called"<< endl;
}
Villager::Villager(string nameInp, int healthInp, string jobInp, int moneyInp)
    : Character{nameInp, healthInp}, job{jobInp}
{
    money = new int;
    *money = moneyInp;
    cout << "Default villager created" << endl;
}
Villager& Villager::operator=(const Villager& other)
{
    if (this == &other)
    {
        return *this;
    }

    Character::operator=(other);
    delete money;
    this->job = other.job;
    this->money = new int;
    *this->money = *other.money;

    return *this;
}
Villager::~Villager()
{
    if (money != nullptr)
    {
        delete money;
    }
    cout << "Villager deleted" << endl;
}
