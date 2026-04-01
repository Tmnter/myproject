#ifndef ENEMY_H
#define ENEMY_H
#include <string>
#include <iostream>

using namespace std;

class Enemy
{
private:
    string type;
    int damage;
    static int countEnemy;
public:
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
    ~Enemy();
};
#endif
