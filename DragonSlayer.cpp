#include "DragonSlayer.h"
#include "Dragon.h"
#include "Character.h"
#include <iostream>
#include <string>
#include <cassert>
#include "Utility.h"
#include "AttackItem.h"

//using base class initialization 
DragonSlayer::DragonSlayer(std::string nm, int x, int y) : name(nm), Character(x, y, 4)
{
    atkItem.reset(new AttackItem());
    helpfulItems = makeHelpfulItems(3);
    defensiveItems = makeDefensiveItems(1);
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
        //assert(false);

    //note: they should only use the item if the dragon's hitpoints are > 0...  
        while( dragon->getHP() > 0 ) //should it be while or just an if? i think this while loop was here. 
        {
            //DragonSlayers get a 10x boost when attacking dragons, from their attack item.            
            //so they should USE their attack item before attacking the dragon... 
            //*initialHitPoints.get()
            *atkItem.get();
                //reset the item.
            atkItem.reset();
            //note: items are single-use only, so you need to reset it after use.  
            //look in the Character class for how the other item types are reset after use.  
            //sounds like we want to use a pointer then. 
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