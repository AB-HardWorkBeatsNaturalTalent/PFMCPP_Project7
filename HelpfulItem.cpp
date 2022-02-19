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
        /*
 6) Each character type gets some Helpful Items and Defensive Items when they're constructed
        Use the functions in Utility.h to give each Character (excluding Dragon, because dragons don't carry items) a RANDOM NUMBER of helpful and defensive items: 
            helpfulItems = makeHelpfulItems(2);
            defensiveItems = makeDefensiveItems(1);*/
}
