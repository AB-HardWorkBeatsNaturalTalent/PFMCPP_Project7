#include "AttackItem.h"
#include "DragonSlayer.h"
#include "Utility.h"

void AttackItem::use(Character* ch)
{   

    //only the dragonslayer uses this for now. 
    //if dynamic cast to DragonSlayer, 
        //
    useAttackItem( ch, this );
}

AttackItem::~AttackItem()
{
    
}

