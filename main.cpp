#include "MainHero.h"
#include "Villager.h"
#include "Enemy.h"
#include <iostream>

using namespace std;

int main()
{
    MainHero object1("Andrij", 100, 5, 10);
    MainHero object2(object1);
    Villager vil1;
    Villager vil2(vil1);
    Villager vil3(move(vil1));
    // метод атаки
    MainHero objectTest;
    object1.Attack(objectTest);

    // const Enemy boss;
    // boss.setdamage();

    //overload <<
    Enemy boss;
    cout << "\n-------------------\nCount of enemy: " << Enemy::getcountEnemy() <<"\n------------------\n"  << endl;
    cout << boss;
    //overload >>
    MainHero object3;
    cin >> object3;
    //overload >
    if(object3 > boss)
        cout << object3.getName() << " can fight!" << endl;
    return 0;
}
