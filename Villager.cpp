#include "Villager.h"
#include <iostream>
#include <string>

using namespace std;
Villager::Villager(Villager&& other)
    : name(move(other.name)), job(move(other.job)), money(other.money) {
    other.money = nullptr;
    cout << "Move constructor called"<< endl;
    }
Villager::Villager(const Villager &other)
: name(other.name), job(other.job) {
money = new int;
*money = *other.money;
cout << "Deep copy constructor called"<< endl;
}
Villager::Villager(string nameInp, string jobInp, int moneyInp)
    : name{nameInp}, job{jobInp} {
money = new int;
*money = moneyInp;
    cout << "Default villager created" << endl;
    }
Villager::~Villager() {
     if (money != nullptr) {
        delete money;
    }
    cout << "Villager deleted" << endl;
}
