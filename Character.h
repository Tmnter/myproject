#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <iostream>

using namespace std;

class Character {
protected:
    string name;
    int health;

public:
    Character(); // Без параметрів
    Character(string n, int hp); // З параметрами
    virtual ~Character();
    string getName() const { return name; }
    int getHealth() const { return health; }
    Character(const Character& other);
    Character(Character&& other) noexcept;
    Character& operator=(const Character& other);
};

#endif
