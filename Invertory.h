#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <iostream>

using namespace std;

class Inventory
{
private:
    string items[5];

public:

    Inventory();

    void showItems() const;
};

#endif
