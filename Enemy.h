#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include <iostream>
#include "Character.h"
using namespace std;

class Enemy : public Character
{
protected:
    string type;
    int damage;
    static int countEnemy;
public:
    string saveToString() const override {
    return "E " + name + " " + to_string(health) + " " + type; // E - маркер ворога
}
    virtual void performAction() override {
    cout << "Enemy " << name << " is preparing to attack!" << endl;
}
    void enemyAction() {
    cout << "Enemy(Base class) - ready to fight!" << endl;
}
    friend ostream& operator<<(ostream &os, const Enemy &enemy);
    static int getcountEnemy()
    {
        return countEnemy;
    }
    void setdamage(int h)
    {
        if(h >= 0) damage = h;
    }
    int getdamage() const
    {
        return damage;
    }
    Enemy(string Inpname = "Monster", int health = 0, string Inptype = "boss", int Inpdamage = 15);
    virtual ~Enemy();
};
#endif
