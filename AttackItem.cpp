#include "AttackItem.h"
#include "Utility.h"

void AttackItem::use(Character* ch)
{   
    useAttackItem( ch, this );
}

AttackItem::~AttackItem()
{
    
}

