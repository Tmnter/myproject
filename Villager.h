#ifndef VILLAGER_H
#define VILLAGER_H
#include <string>
#include <iostream>

using namespace std;

class Villager
{
private:
    string job;
    int* money;
public:
    Villager(Villager &&other);
    Villager(const Villager &other);
    Villager(string nameInp = "None", int healthInp = 0, string jobInp = "Farmer", int moneyInp = 0);
    ~Villager();
};
#endif
