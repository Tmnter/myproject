#ifndef DEALER_H
#define DEALER_H

#include "Villager.h"
#include "Inventory.h"
#include <string>

using namespace std;

class Dealer : public Villager {
private:
    Inventory shop;

public:
    Dealer(string nameInp, string jobInp, int moneyInp);

    void trade();
};

#endif
