#include "DragonSlayer.h"
#include "Dragon.h"
#include "Utility.h"
#include "AttackItem.h"

//using base class initialization 
DragonSlayer::DragonSlayer(std::string nm, int x, int y) :  Character( x, y, 4), name(nm)
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
    //note: they should only use the item if the dragon's hitpoints are > 0...  
        while( dragon->getHP() > 0 ) 
        {
            //DragonSlayers get a 10x boost when attacking dragons, from their attack item.  
            //so they should USE their attack item before attacking the dragon... 
            if(atkItem)
            {//note: items are single-use only, so you need to reset it after use.
                atkItem.get()->use(this);               
                atkItem.reset(); //reset the item. 
            }           
            //look in the Character class for how the other item types are reset after use.  
            //sounds like we want to use a pointer then. 
            dragon->takeDamage(attackDamage);
        }
    }        
    Character::attack(other);        
}

std::string DragonSlayer::getStats() 
{
    return getCharacterStats(this);
}

