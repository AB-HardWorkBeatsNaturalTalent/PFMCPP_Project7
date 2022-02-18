#include "Paladin.h"
#include "Character.h"
#include <string>

Paladin(std::string nm, int x, int y) : Character(x,y,3), name(nm)
{
    
}

const std::string& getName()
{
    return name;
}
std::string getStats()
{
    
}
