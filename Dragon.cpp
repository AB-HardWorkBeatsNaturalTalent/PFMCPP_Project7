#include "Dragon.h"
#include "DragonSlayer.h"


 Dragon::Dragon(std::string nm, int x, int y)
{
    
}

void Dragon::attack(Character &other) override
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

const std::string& getName() override
{
    
}
std::string getStats() override
{
    
}