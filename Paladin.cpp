#include "Paladin.h"
#include "Utility.h"

//using base class initialization
Paladin::Paladin(std::string nm, int hp, int armor) : Character( hp, armor, 10), name(nm)
{
    helpfulItems = makeHelpfulItems(2);
    defensiveItems = makeDefensiveItems(6);
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
