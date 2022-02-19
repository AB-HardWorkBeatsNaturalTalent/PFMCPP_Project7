#include "Character.h"
#include <iostream>
#include <vector>

#include "DefensiveItem.h"
#include "HelpfulItem.h"
#include "Utility.h"

Character::Character(int hp, int armor_, int attackDamage_ ) :
    hitPoints(hp),
    armor(armor_),
    attackDamage(attackDamage_)
{
    initialHitPoints.reset( new int( hitPoints ) );
    initialArmorLevel.reset( new int( armor) );
    initialAttackDamage.reset( new int( attackDamage) );
}

void Character::attack( Character& other )
{
    if( hitPoints <= 0 )
    {
        std::cout << getName() << " can't attack. " << getName() << " is dead." << std::endl;
        std::cout << "make another party member use an item to revive them" << std::endl << std::endl;
        return;
    }
        
    isDefending = false;
    std::cout << getName() << " has attacked " << other.getName() << std::endl;
    
    if( other.takeDamage(attackDamage) <= 0 ) 
    {
        //if you kill other, you get a boost in hit points and armor.
        attackInternal(other);
    }
}

void Character::defend()
{
    std::cout << getName() << " is defending!!" << std::endl;
    for( auto& item : defensiveItems )
    {
        if( auto* defensiveItem = dynamic_cast<DefensiveItem*>(item.get()) )
        {
            defensiveItem->use(this);
            item.reset(); //can only be used once!
            break;
        }
    }
    isDefending = true;
}

void Character::help(Character& other)
{
    std::cout << getName() << " is going to help " << other.getName() << std::endl;
    for( auto& item : helpfulItems )//give me a reference to each item
    {
        if( auto* helpfulItem = dynamic_cast<HelpfulItem*>(item.get()) )
        {
            helpfulItem->use(&other);
            item.reset(); //can only be used once!
            break;
        }
    }
}

int Character::takeDamage(int damage)
{
    std::cout << getName() << " is taking " << damage << " damage!" << std::endl;
    if( damage < armor )
    {
        armor -= damage;
    }
    else
    {
        damage -= armor;
        armor = 0;
        
        hitPoints -= damage;
        if( hitPoints < 0 )
        {
            std::cout << getName() << " has died in battle!" << std::endl;
            hitPoints = 0;
        }
    }
    printStats();
    return hitPoints;
}

void Character::attackInternal(Character& other)
{
    //you should not be doing this for a Dragon, it seems.
    
    if( other.hitPoints <= 0 )
    {
        std::cout << getName() << " defeated " << other.getName() << " and leveled up!" << std::endl; 
        /* When you defeat another Character: 
        a) your stats are restored to their initial value if they are lower than it.*/     
        if(hitPoints < *initialHitPoints.get()) 
            hitPoints = *initialHitPoints.get();        
        if(armor < *initialArmorLevel.get()) 
            armor = *initialArmorLevel.get();
        if( attackDamage < *initialAttackDamage.get()) 
            attackDamage = *initialAttackDamage.get();        
    /*
        b) your stats are boosted 10% */
        //get the initial amount * 10%
        int temp = *initialAttackDamage.get() * .1;
        boostAttackDamage(temp);
        //get the initial amount * 10%
        temp = *initialHitPoints.get() * .1;
        boostHitPoints(temp);
        //get the initial amount * 10%
        temp = *initialArmorLevel.get() * .1;
        boostArmor(temp);
    /* 
        c) the initial value of your stats is updated to reflect this boosted stat for 
the next time you defeat another character.*/   
        *initialAttackDamage = getAttackDamage();
        *initialArmorLevel = getArmorLevel();
        *initialHitPoints = getHP();       
    }
}

void Character::printStats()
{
    std::cout << getName() << "'s stats: " << std::endl;
    //assert(false);
    /*
    make your getStats() use a function from the Utility.h
    */
    std::cout << getCharacterStats(this); 
    
    std::cout << std::endl;
    std::cout << std::endl;
}
