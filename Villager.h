#ifndef VILLAGER_H
#define VILLAGER_H
#include <string>
#include <iostream>
#include "Character.h"
using namespace std;

class Villager : public Character
{
protected:
    string job;
    int* money;
public:
    Villager& operator=(const Villager& other);
    Villager(Villager &&other);
    Villager(const Villager &other);
    Villager(string nameInp = "None", int healthInp = 0, string jobInp = "Farmer", int moneyInp = 0);
    ~Villager();
};
#endif
