#include "Villager.h"
#include <iostream>
#include <string>

using namespace std;
Villager::Villager(string nameInp, string jobInp)
    : name{nameInp}, job{jobInp} {
    cout << "Default villager created" << endl;
    }
Villager::~Villager() {
    cout << "Villager deleted" << endl;
}
