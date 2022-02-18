#include "AttackItem.h"
#include "DefensiveItem.h"
#include "Dwarf.h"
#include "Paladin.h"
#include "DragonSlayer.h"
#include "Dragon.h"
#include "Utility.h"

void AttackItem::use(Character* ch)
{
    useAttackItem( ch, this );

    //depending on the character type that uses it,
        //do somethign different.
    
}

