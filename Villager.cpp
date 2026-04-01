#include "Villager.h"
#include <iostream>
#include <string>

using namespace std;
Villager::Villager(Villager&& other)
    : Character{move(other)}, job{move(other.job)}
{
    this->money = other.money;
    other.money = nullptr;
    cout << "Move constructor called"<< endl;
}
Villager::Villager(const Villager &other)
    : Character{other}, job{other.job}
{
    money = new int;
    *money = *other.money;
    cout << "Deep copy constructor called"<< endl;
}
Villager::Villager(string nameInp, int healthInp, string jobInp, int moneyInp)
    : Character{nameInp, healthInp}, job{jobInp}
{
    money = new int;
    *money = moneyInp;
    cout << "Default villager created" << endl;
}
Villager& Villager::operator=(const Villager& other) {
    // 1. ПЕРЕВІРКА НА САМОПРИСВОЄННЯ
    // Якщо написати v1 = v1, ми не маємо нічого робити
    if (this == &other) {
        return *this;
    }

    // 2. ВИКЛИК ОПЕРАТОРА БАТЬКА
    // Character має скопіювати свої name та health
    Character::operator=(other);

    // 3. ОЧИЩЕННЯ ВЛАСНИХ СТАРИХ РЕСУРСІВ
    // Видаляємо старі гроші, щоб не було витоку пам'яті
    delete money;

    // 4. КОПІЮВАННЯ НОВИХ ДАНИХ
    this->job = other.job;
    this->money = new int; // Створюємо нову комірку
    *this->money = *other.money; // Копіюємо значення

    // 5. ПОВЕРНЕННЯ ОБ'ЄКТА
    // Потрібно для ланцюжків типу v1 = v2 = v3;
    return *this;
}
Villager::~Villager()
{
    if (money != nullptr)
    {
        delete money;
    }
    cout << "Villager deleted" << endl;
}
