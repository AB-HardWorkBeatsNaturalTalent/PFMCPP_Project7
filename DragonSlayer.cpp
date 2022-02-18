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

    //note: they should only use the item if the dragon's hitpoints are > 0...  
        while( dragon->getHP() > 0 )
        {
            //DragonSlayers get a 10x boost when attacking dragons, from their attack item.            
            //so they should USE their attack item before attacking the dragon... 
            useAttackItem(*this, /*atk item here*/);
            //for each item in this characters list of attack items, 
                //use the item, 
                //reset the item.
            //note: items are single-use only, so you need to reset it after use.  
            //look in the Character class for how the other item types are reset after use.  
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