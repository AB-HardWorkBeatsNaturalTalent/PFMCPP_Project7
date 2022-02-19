#include "Dragon.h"
#include "DragonSlayer.h"
#include "Utility.h"
#include "Character.h"
#include <string>

//using base class initialization
Dragon::Dragon(std::string nm, int x, int y) : Character(x, y, 80), name(nm)
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
        //should we be calling the most derived. 
    }
}

const std::string& Dragon::getName()
{
    return name;
}
std::string Dragon::getStats()
{
    return getCharacterStats(this);
}
