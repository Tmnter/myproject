#ifndef PROGRAM_H_INCLUDED
#define PROGRAM_H_INCLUDED
#include <string>
#include <memory>
#include <vector>
#include "Location.h"

class Program {
public:
    void runProgram();
private:
    void interactWithNPC(int locIdx);
    int changeLocation();
    void saveWorldToFile(const std::string& filename);
    void addNpcToLocation();
    void createLocation();
    void logAction(const std::string& message);
    void loadWorldFromFile(const std::string& filename);
    std::vector<std::shared_ptr<Location>> WorldMap;
    const std::string PasswordAdmin = "AdminRPG";
    bool isAdmin = false;
    void AdminSecurity();
    void MainMenu();
    void MenuAdmin();
    void MenuUser();
};
#endif // PROGRAM_H_INCLUDED
