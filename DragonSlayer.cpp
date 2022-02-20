#include "DragonSlayer.h"
#include "Dragon.h"
#include "Utility.h"
#include "AttackItem.h"

//using base class initialization 
DragonSlayer::DragonSlayer(std::string nm, int hp, int armor) :  Character( hp, armor, 4), name(nm)
{
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
        atkItem.get()->use(this);               
        atkItem.reset(); //note: items are single-use only, so you need to reset it after use. 
        while( dragon->getHP() > 0 ) 
        {
            //DragonSlayers get a 10x boost when attacking dragons, from their attack item.  
            //so they should USE their attack item before attacking the dragon... 
            //look in the Character class for how the other item types are reset after use. 
            dragon->takeDamage(attackDamage);
        }
    }        
    Character::attack(other);        
}

std::string DragonSlayer::getStats() 
{
    return getCharacterStats(this);
}

