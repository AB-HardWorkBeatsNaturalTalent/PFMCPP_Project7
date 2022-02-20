#include "HelpfulItem.h"
#include "Utility.h"

void HelpfulItem::use(Character *character)
{
    //use the helpful item. 
    useHelpfulItem(character, this);
}
