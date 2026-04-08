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
    void performAction() override {
    cout << "Villager " << name << " is farming with job: " << job << endl;
}
void printInfo() const override {
    cout << "Type: Villager | Name: " << name << " | Job: " << job << " | Money: " << *money << endl;
}
    Villager& operator=(const Villager& other);
    Villager(Villager &&other);
    Villager(const Villager &other);
    Villager(string nameInp = "None", int healthInp = 0, string jobInp = "Farmer", int moneyInp = 0);
    ~Villager();
};
#endif
