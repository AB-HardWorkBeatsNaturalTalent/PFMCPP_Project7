#include "Paladin.h"
#include "Character.h"
#include <string>
#include "Utility.h"

Paladin::Paladin(std::string nm, int x, int y) : Character(x,y,3), name(nm)
{
    
}

const std::string& Paladin::getName()
{
    return name;
}

std::string Paladin::getStats()
{
    return getCharacterStats(this);
}

void Paladin::attack(Character& other)
{
    
}
