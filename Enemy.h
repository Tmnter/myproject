#ifndef CHARACTERS3_H
#define CHARACTERS3_H
#include <string>
#include <iostream>

using namespace std;

class Enemy {
private:
    string name;
    string type;
    int damage;
public:
    Enemy(string Inpname = "Monster", string Inptype = "boss", int Inpdamage = 15);
    ~Enemy();
};
#endif
