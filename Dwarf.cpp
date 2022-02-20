#include "Dwarf.h"
#include "Utility.h"
#include <string>
#include "Character.h"

//using base class initialization
Dwarf::Dwarf(std::string nm, int x, int y) : Character(x, y, 4), name(nm)
{
    helpfulItems = makeHelpfulItems(2);
    defensiveItems = makeDefensiveItems(5);
}

const std::string& Dwarf::getName()
{
    return name;
}

std::string Dwarf::getStats()
{
    return getCharacterStats(this);
}

void Dwarf::attack(Character& other)
{
    Character::attack(other);
}

