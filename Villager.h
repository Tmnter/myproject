#ifndef CHARACTERS2_H
#define CHARACTERS2_H
#include <string>
#include <iostream>

using namespace std;

class Villager {
private:
    string name;
    string job;
public:
    Villager(string nameInp = "None", string jobInp = "Farmer");
    ~Villager();
};
#endif
