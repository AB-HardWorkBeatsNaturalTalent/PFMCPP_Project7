#include "Dragon.h"
#include "DragonSlayer.h"
#include "Utility.h"
#include "Character.h"
#include <string>

Dragon::Dragon(std::string nm, int x, int y) : name(nm), Character(x, y, 5)
{
    
}

void Dragon::attack(Character &other)
{
    std::cout << name << " is attacking " << other.getName() << "!!!" << std::endl;
    if( auto* slayer = dynamic_cast<DragonSlayer*>(&other) )
    {
        //dragons can't attack dragon slayers
        slayer->defend();
    }
    else
    {
        Character::attack(other);
    }
}

const std::string& Dragon::getName()
{
    
}
std::string Dragon::getStats()
{
    return getCharacterStats(this);
}
