#ifndef SUPERPOWER_H
#define SUPERPOWER_H
#include <string>
#include <iostream>

using namespace std;

class Superpower {
private:
    string name;
    int damage;
    string effect;

public:
    Superpower();
    Superpower(string n, int d, string eff);
    void use() const;
};

#endif
