#include "Dwarf.h"
#include "Utility.h"
#include <string>
#include "Character.h"

Dwarf::Dwarf(std::string nm, int x, int y) : name(nm), Character(x,y, 10)
{
    
}

const std::string& Dwarf::getName()
{
    return name;
}

std::string Dwarf::getStats()
{
    return getCharacterStats(this);
}

void attack(Character& other)
{
    
}
