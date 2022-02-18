#include "HelpfulItem.h"
#include "DefensiveItem.h"
#include "Dwarf.h"
#include "Paladin.h"
#include "DragonSlayer.h"
#include "Dragon.h"
#include "Utility.h"

void HelpfulItem::use(Character *character)
{
    //use the helpful item. 
    useHelpfulItem(character, this);
}
