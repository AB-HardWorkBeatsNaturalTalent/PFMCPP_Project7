#include "Paladin.h"
#include "Character.h"
#include <string>
#include "Utility.h"
#include "DefensiveItem.h"

//using base class initialization
Paladin::Paladin(std::string nm, int x, int y) : Character(x,y,10), name(nm)
{
    
}

const std::string& Paladin::getName()
{
    return name;
}

std::string getStats() /*override, causes error expected func body */
{
    return getCharacterStats(this);
}

void Paladin::attack(Character& other)
{
    
}
