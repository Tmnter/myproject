#include "Character.h" // Обов'язково підключаємо хедер

Character::Character(string Inpname, int Inphealth)
    : name{Inpname}, health{Inphealth}
{
    cout << "Character " << name << " created" << endl;
}

Character::Character() : Character("Unknown", 0)
{
    cout << "Default Character created" << endl;
}

Character::Character(const Character& other)
    : name{other.name}, health{other.health}
{
    cout << "Character copy constructor (" << name << ")" << endl;
}
Character::Character(Character&& other) noexcept
    : name{std::move(other.name)}, health{other.health}
{
    other.health = 0;
    cout << "Character move constructor (" << name << ")" << endl;
}

Character& Character::operator=(const Character& other)
{
    if (this == &other) return *this;

    this->name = other.name;
    this->health = other.health;

    cout << "Character operator= (" << name << ")" << endl;
    return *this;
}

Character::~Character()
{
    cout << "Character " << name << " deleted" << endl;
}
