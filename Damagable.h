#ifndef DAMAGABLE_H_INCLUDED
#define DAMAGABLE_H_INCLUDED
class Damagable {
public:
    // Чисто віртуальна функція: як саме об'єкт реагує на удар
    virtual void takeDamage(int amount) = 0;

    virtual ~Damagable() {}
};


#endif // DAMAGABLE_H_INCLUDED
