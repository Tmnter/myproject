#ifndef OBSTACLE_H_INCLUDED
#define OBSTACLE_H_INCLUDED
class Obstacle : public Damagable {
private:
    int durability;
public:
    Obstacle(int hp) : durability(hp) {}

    void takeDamage(int amount) override {
        durability -= (amount / 2); // Наприклад, перешкоди мають опір і отримують менше шкоди
        cout << "Obstacle hit! Durability left: " << durability << endl;
        if (durability <= 0) cout << "The obstacle is destroyed!" << endl;
    }
};
#endif // OBSTACLE_H_INCLUDED
