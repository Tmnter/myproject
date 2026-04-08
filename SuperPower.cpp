#include "Superpower.h"
#include <iostream>
Superpower::Superpower()
    : name{"Simple Punch"}, damage{5}, effect{"No effect"}
{
    cout << "Superpower Default constructor called" << endl;
}
Superpower::Superpower(string nameInp, int damageInp, string effectInp)
    : name{nameInp}, damage{damageInp}, effect{effectInp}
{
    cout << "Superpower constructor with parameters called " << name << endl;
}

void Superpower::use() const
{
    cout << "> Ability: " << name << " | Damage: " << damage << " | Effect: " << effect << endl;
}
