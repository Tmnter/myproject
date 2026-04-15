#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <iostream>
#include "Damagable.h"
using namespace std;

class Character : public Damagable
{
protected:
    string name;
    int health;

public:
    void takeDamage(int amount) override {
        health -= amount;
        cout << name << " took " << amount << " damage. Remaining HP: " << health << endl;
    }
virtual string saveToString() const = 0;
virtual void performAction() = 0;
virtual void printInfo() const {
    cout << "Type: Character | Name: " << name << " | HP: " << health << endl;
}
    Character();
    Character(string n, int hp);
    virtual ~Character();
    string getName() const
    {
        return name;
    }
    int getHealth() const
    {
        return health;
    }
    Character(const Character& other);
    Character(Character&& other) noexcept;
    Character& operator=(const Character& other);
};

#endif
