#include "Inventory.h"
#include <iostream>

using namespace std;

Inventory::Inventory() {
    items[0] = "Health Potion";
    items[1] = "Mana Potion";
    items[2] = "Iron Sword";
    items[3] = "Leather Armor";
    items[4] = "Lucky Charm";

    cout << "Inventory Default items loaded into the shop" << endl;
}

void Inventory::showItems() const {
    cout << "--- Current Stock ---" << endl;
    for (int i = 0; i < 5; i++) {
        if (!items[i].empty()) {
            cout << i + 1 << ". " << items[i] << endl;
        }
    }
    cout << "---------------------" << endl;
}
