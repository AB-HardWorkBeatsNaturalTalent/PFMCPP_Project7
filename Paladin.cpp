#include "Paladin.h"
#include "Character.h"
#include <string>
#include "Utility.h"
#include "DefensiveItem.h"

//using base class initialization
Paladin::Paladin(std::string nm, int x, int y) : Character(x,y,10), name(nm)
{
    helpfulItems = makeHelpfulItems(3);
    defensiveItems = makeDefensiveItems(7);
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
    Character::attack(other);
}
