#include "DefensiveItem.h"
#include "Dwarf.h"
#include "Paladin.h"
#include "DragonSlayer.h"
#include "Dragon.h"
#include <cassert>
#include "Utility.h"
void DefensiveItem::use(Character* character)
{
    useDefensiveItem(character, *this);
    //assert(false); 
    //make your defensive item use the appropriate Utility helper functions
    
    //loop through items, cast to defensive item.
    //

    /*
 6) Each character type gets some Helpful Items and Defensive Items when they're constructed
        Use the functions in Utility.h to give each Character (excluding Dragon, because dragons don't carry items) a RANDOM NUMBER of helpful and defensive items: 
            helpfulItems = makeHelpfulItems(2);
            defensiveItems = makeDefensiveItems(1);*/
}
