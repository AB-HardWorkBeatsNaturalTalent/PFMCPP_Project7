#include "Dwarf.h"
#include "Utility.h"
#include <string>

Dwarf::Dwarf(std::string nm, int x, int y) : name(nm), Character.hitpoints(x), Character.armor(y)
{
    
}

void const std::string& Dwarf::getName()
{
    return name;
}

std::string Dwarf::getStats()
{
    return getCharacterStats();
}

void attack(Character& other)
{
    
}