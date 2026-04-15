#include "Program.h"
#include "Location.h"
#include <iostream>
#include "Villager.h"
#include "Enemy.h"
#include <fstream>
#include <sstream>
using namespace std;
void Program::runProgram() {
loadWorldFromFile("world.txt");
logAction("SYSTEM: World data loaded from file.");
int choice = -1;
while(choice != 0) {
    Program::MainMenu();
        std::cout << "Select a menu item" << endl;
        std::cin >> choice;
        switch (choice) {
        case 1:
            Program::AdminSecurity();
            break;
        case 2:
            Program::MenuUser();
            break;
        case 0:
            std::cout << "Exit the program . . ." << endl;
            break;
        default:
            std::cout << "Does not exist" << endl;
        }
}
}
void Program::MainMenu() {
std::cout << "===CHOICE OF ACCESS RIGHTS===" << endl;
std::cout << endl;
std::cout << "  1. ADMIN LOGIN" << endl;
std::cout << "  2. USER LOGIN" << endl;
std::cout << "  0. EXIT" << endl;
std::cout << endl;
}
void Program::AdminSecurity() {
    string inputKey;
    bool exitSecurity = false;

    while (!exitSecurity) {
        std::cout << "ADMIN LOGIN . . .(type '0' to cancel)" << endl;
        std::cout << "Enter password: " << endl;
        std::cin >> inputKey;

        if (inputKey == "0") {
            std::cout << "Exiting login screen..." << endl;
            exitSecurity = true;
        }
        else if (inputKey == PasswordAdmin) {
            logAction("LOGIN: Admin entered the system.");
            isAdmin = true;
            std::cout << "Login is successful!" << endl;
            MenuAdmin();
            exitSecurity = true;
        }
        else {
            logAction("WARNING: Failed admin login");
            isAdmin = false;
            std::cout << "The password is incorrect!" << endl;
            std::cout << "Try again or input '0' to return to main menu." << endl;
        }
    }
}
void Program::MenuAdmin() {
    int Achoice = -1;
    while (Achoice != 0) {
        std::cout << "\n=== ADMIN MENU ===" << endl;
        std::cout << "1. Create new location" << endl;
        std::cout << "2. Add NPC in location" << endl;
        std::cout << "0. Return to the main menu" << endl;
        std::cin >> Achoice;
        switch(Achoice) {
        case 1:
            Program::createLocation();
            break;
        case 2:
            Program::addNpcToLocation();
            break;
        case 0:
            saveWorldToFile("world.txt");
            std::cout << "Return to the main menu . . . . " << endl;
            break;
        default:
            std::cout << "Incorrect item" << endl;
            break;
        }
    }
}
void Program::logAction(const string& message) {
    ofstream logFile("history.txt", std::ios::app);
    if (logFile.is_open()) {
        logFile << message << endl;
        logFile.close();
    }
}
void Program::createLocation() {
    string name, desc;
    cout << "Enter name of location: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter description: ";
    getline(cin, desc);

    WorldMap.push_back(make_shared<Location>(name, desc));
    logAction("DATABASE: New location created - " + name);
    cout << "LOCATION CREATED!" << endl;
}
void Program::addNpcToLocation() {
    if (WorldMap.empty()) {
        cout << "Error, there is not any location!" << endl;
        return;
    }


    cout << "Choose location for NPC (1-" << WorldMap.size() << "):" << endl;
    for (int i = 0; i < WorldMap.size(); i++) {
        cout << i + 1 << ". " << WorldMap[i]->name << endl;
    }
    int locIdx; cin >> locIdx;

    if (locIdx < 1 || locIdx > WorldMap.size()) return;
    cout << "Choose type of NPC! 1 - Villager, 2 - Enemy: ";
    int type; cin >> type;

    string name;
    cout << "Enter name of NPC: ";
    cin.ignore(); getline(cin, name);

    shared_ptr<Character> newUnit;
    if (type == 1) {
        newUnit = make_shared<Villager>(name, 100);
    } else {
        newUnit = make_shared<Enemy>(name, 100, "Ork", 20);
    }

    WorldMap[locIdx - 1]->localNPCs.push_back(newUnit);

    cout << "NPC " << name << " created in location " << WorldMap[locIdx - 1]->name << endl;
}
void Program::saveWorldToFile(const string& filename) {
    ofstream outFile(filename);

    if (!outFile.is_open()) {
        cout << "Error the open of file!" << endl;
        return;
    }

    for (const auto& loc : WorldMap) {
        outFile << "L " << loc->name << " " << loc->description << endl;
        for (const auto& npc : loc->localNPCs) {
            outFile << "N " << npc->saveToString() << endl;
        }
    }

    outFile.close();
    cout << "World saved in file" << endl;
}
void Program::loadWorldFromFile(const string& world) {
    ifstream inFile(world);
    if (!inFile.is_open()) return;

    WorldMap.clear();
    shared_ptr<Location> currentLoc = nullptr;

    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        char marker;
        ss >> marker;

        if (marker == 'L') {
            string name, desc;
            ss >> name;
            getline(ss, desc);

            currentLoc = make_shared<Location>(name, desc);
            WorldMap.push_back(currentLoc);
        }
        else if (marker == 'N' && currentLoc != nullptr) {
            string type, name;
            ss >> type >> name;

            if (type == "Villager") {
                int money; ss >> money;
                currentLoc->localNPCs.push_back(make_shared<Villager>(name, money));
            }
            else if (type == "Enemy") {
                int health; string race; int damage;
                ss >> health >> race >> damage;
                currentLoc->localNPCs.push_back(make_shared<Enemy>(name, health, race, damage));
            }
        }
    }
    inFile.close();
}
void Program::MenuUser() {
    int userChoice = -1;
    int currentLocIdx = 0;

    while (userChoice != 0) {
        if (WorldMap.empty()) {
            cout << "World is empty!" << endl;
            return;
        }

        auto& loc = WorldMap[currentLocIdx];
        cout << "\n== YOU NOW IN : " << loc->name << " ===" << endl;
        cout << loc->description << endl;

        cout << endl;
        cout << "1. Moved to other location" << endl;
        cout << "2. Interact with NPC" << endl;
        cout << "0. Exit" << endl;
        cout << "Your choice: ";
        cin >> userChoice;

        switch (userChoice) {
            case 1:
                try {
        int nextLoc = changeLocation();
        if (nextLoc != -1) {
            currentLocIdx = nextLoc;
            cout << "You moved succesfully!" << endl;
        }
    }
    catch (const string& errorMsg) {
        cout << "\n Error in travel : " << errorMsg << endl;
        logAction("EXCEPTION in changeLocation: " + errorMsg);

    } break;
            case 2: try {
        interactWithNPC(currentLocIdx);
    }
    catch (const string& errorMsg) {
        cout << "\n[ÏÎÌÈËÊÀ ÂÇÀªÌÎÄ²¯]: " << errorMsg << endl;
        logAction("EXCEPTION in interactWithNPC: " + errorMsg);
    } break;
        }
    }
}
void Program::interactWithNPC(int locIdx) {
    auto& loc = WorldMap[locIdx];

    if (loc->localNPCs.empty()) {
        cout << "There is not any people" << endl;
        return;
    }

    cout << "\n=== CHARACTER NEAR YOU ===" << endl;
    for(int i = 0; i < loc->localNPCs.size(); i++) {
        cout << i + 1 << ". " << loc->localNPCs[i]->getName() << endl;
    }

    cout << "Choose number (or 0 to cancel): ";
    int npcIdx;
       if (!(cin >> npcIdx)) {
        cin.clear();
        cin.ignore(1000, '\n');
        throw string("You dont enter number!");
    }

    if (npcIdx == 0) return;

    if (npcIdx < 1 || npcIdx > loc->localNPCs.size()) {
        throw string("NPC with name " + to_string(npcIdx) + " dont exist");
    }
    cout << "\n ===  ";
    loc->localNPCs[npcIdx - 1]->performAction();

    logAction("PLAYER: Interaction with " + loc->localNPCs[npcIdx - 1]->getName());
}
int Program::changeLocation() {
    cout << "\n WHERE DO YOU WANT GO?" << endl;

    if (WorldMap.empty()) {
        throw string("World is empty!");
    }

    for (int i = 0; i < WorldMap.size(); i++) {
        cout << i + 1 << ". " << WorldMap[i]->name << endl;
    }
    cout << "0. Cancel " << endl;

    int choice;
    cout << "Your choice: ";
    if (!(cin >> choice)) {
        cin.clear();
        cin.ignore(1000, '\n');
        throw string("Critical error, you dont enter number.");
    }

    if (choice == 0) return -1;

    if (choice < 1 || choice > WorldMap.size()) {
        throw string("Location with number " + to_string(choice) + " dont exist!");
    }

    logAction("PLAYER: Successfully moved to " + WorldMap[choice - 1]->name);
    return choice - 1;
}
