#include "DragonSlayer.h"
#include "Dragon.h"
#include "Character.h"
#include <iostream>
#include <string>
#include <cassert>
#include "Utility.h"

//using base class initialization 
DragonSlayer::DragonSlayer(std::string nm, int x, int y) : name(nm), Character(x, y, 5)
{
    
}

//DragonSlayer::getName
const std::string& DragonSlayer::getName() 
{
    return name;   
}

void DragonSlayer::attack(Character& other) 
{
    std::cout << name << " is attacking " << other.getName() << " !!" << std::endl;
    if( auto* dragon = dynamic_cast<Dragon*>(&other) )
    {
        assert(false);
        //DragonSlayers get a 10x boost when attacking dragons, from their attack item.    
        //this.boostAttackDamage(10);
        //so they should USE their attack item before attacking the dragon... 
        //note: they should only use the item if the dragon's hitpoints are > 0...
        //note: items are single-use only, so you need to reset it after use.  
        //look in the Character class for how the other item types are reset after use.
        while( dragon->getHP() > 0 )
        {
            dragon->takeDamage(attackDamage);
        }
    }
        
    Character::attack(other);
        
}

//DragonSlayer::getStats
std::string DragonSlayer::getStats() 
{
    return getCharacterStats(this);
}