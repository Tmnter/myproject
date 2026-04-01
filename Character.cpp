class Character {
protected:
    string name;
    int health;
public:
    Character(string Inpname, int Inphealth) : name{Inpname}, health{Inphealth} {
    cout << "Character" << name << "created" << endl;
    }
    Character() : Character("Unknown", 0) {
    cout << "Default Character created" << endl;
    }
    virtual ~Character() {}
};
