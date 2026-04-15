#ifndef LOCATION_H_INCLUDED
#define LOCATION_H_INCLUDED
#include <string>
#include <vector>
#include <memory>
#include "Character.h"
class Location {
public:
    std::string name;
    std::string description;
    std::vector<std::shared_ptr<Character>> localNPCs;

    Location(string n, string d) : name(n), description(d) {}
};
#endif // LOCATION_H_INCLUDED
