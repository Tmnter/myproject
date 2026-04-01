#include "Dealer.h"
#include <iostream>

Dealer::Dealer(string nameInp, string jobInp, int moneyInp)
    : Villager{nameInp, 100, jobInp, moneyInp} // Виклик конструктора Villager
{
    // Об'єкт 'shop' ініціалізується автоматично конструктором за замовчуванням Inventory
    cout << "Dealer " << name << " opened a shop!" << endl;
}

void Dealer::trade() {
    cout << name << " says: 'Take a look at my goods!'" << endl;
    shop.showItems(); // Викликаємо метод вкладеного об'єкта
}
