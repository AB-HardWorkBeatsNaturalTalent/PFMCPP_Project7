#include "Utility.h"

#include "HelpfulItem.h"
#include "DefensiveItem.h"
#include "Character.h"
#include "Paladin.h"
#include "DragonSlayer.h"
#include "Dragon.h"
//struct Character;

std::vector<std::unique_ptr<Item>> makeHelpfulItems(int num)
{
    std::vector<std::unique_ptr<Item>> items;
    
    while( num-- >= 0 )
    {
        items.push_back( std::unique_ptr<HelpfulItem>(new HelpfulItem()) );
    }
    
    std::cout << "made " << items.size() << " helpful items" << std::endl;
    return items;
}

std::vector<std::unique_ptr<Item>> makeDefensiveItems(int num)
{
    std::vector<std::unique_ptr<Item>> items;
    
    while( num-- >= 0 )
    {
        items.push_back( std::unique_ptr<DefensiveItem>(new DefensiveItem()) );
    }
    
    std::cout << "made " << items.size() << " defensive items" << std::endl;
    return items;
}

std::string getCharacterStats(Character* ch1)
{
    std::string str;
    
    str += "    hitPoints: " + std::to_string(ch1->getHP()) + "\n";
    str += "    armor: " + std::to_string(ch1->getArmorLevel()) + "\n";
    str += "    attack damage: " + std::to_string(ch1->getAttackDamage()) + "\n";
    str += "    is defending: " + std::string((ch1->getIsDefending() ? "true" : "false" )) + "\n";
    str += "    " + std::to_string(ch1->getHelpfulItems().size()) + " helpful items,  " + std::to_string(ch1->getDefensiveItems().size()) + " defensive items";
    return str;
}

void useDefensiveItem(Character* character1, Item& item)
{
    //dwarves, paladins, and DragonSlayers get extra boosts from defensive item.
    if( auto* ch = dynamic_cast<Dwarf*>(character1) )
    {
        ch->boostArmor( item.getBoost() * 1.1 );
    }
    else if( auto* ch = dynamic_cast<Paladin*>(character1) )
    {
        //same with paladins
        ch->boostArmor( item.getBoost() * 1.3 );
    }
    else if( auto* ch = dynamic_cast<DragonSlayer*>(character1))
    {
        ch->boostArmor( item.getBoost() * 1.5 );
    }
    else if( auto* ch = dynamic_cast<Dragon*>(character1) )
    {
        //dragons don't need defensive items
    }  
}
void useHelpfulItem(Character* character2, Item* item)
{
    if( auto* ch = dynamic_cast<Dwarf*>(character2) )
    {
        ch->boostHitPoints(item->getBoost() * 2);
    }
    else if( auto* ch = dynamic_cast<Paladin*>(character2) )
    {
        ch->boostHitPoints(item->getBoost() * 1.5);
    }
    else if( auto* ch = dynamic_cast<DragonSlayer*>(character2))
    {
        ch->boostHitPoints(item->getBoost() * 1.25);
    }
    else if( auto* ch = dynamic_cast<Dragon*>(character2) )
    {
        //dragons don't carry helpful items!
    }
}
void useAttackItem(Character* character3, Item* item)
{
    if( auto* ch = dynamic_cast<Dwarf*>(character3) )
    {
        ch->boostAttackDamage(item->getBoost() * 1.5);
    }
    else if( auto* ch = dynamic_cast<Paladin*>(character3) )
    {
        ch->boostAttackDamage(item->getBoost() * 1.33);
    }
    else if( auto* ch = dynamic_cast<DragonSlayer*>(character3))
    {
        //assert(false);
        //DragonSlayers get a 10x boost when attacking dragons, from their attack item.
        ch->boostAttackDamage(item->getBoost() * 10);
        //so their attack item should boost their attack damage by a factor of 10
        //this means you need to GET the attack damage, multiply it by the item's boost, and BOOST the attackDamage with that multiplied value.  
        //check Character.h for available member functions you can use.
    }
    else if( auto* ch = dynamic_cast<Dragon*>(character3) )
    {
        //dragons don't carry attack items!
    }
}
