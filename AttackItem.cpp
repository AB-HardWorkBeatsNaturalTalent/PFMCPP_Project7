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
}

