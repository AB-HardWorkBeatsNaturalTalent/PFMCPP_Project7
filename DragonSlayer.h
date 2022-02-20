#pragma once

#include "Character.h"
#include "AttackItem.h"
#include <memory>
struct DragonSlayer : Character
{
    DragonSlayer(std::string name, int hp, int armor);
    void attack(Character& other) override;
    std::string getStats() override;
    const std::string& getName() override;

    /* 
7) create a new Item-derived type that boosts the attack damage called AttackItem 
        add an instance of it to the DragonSlayer class
        make the DragonSlayer::attack use it when the dragonSlayer attacks a dragon. */
    
private:
    const std::string name;
    std::unique_ptr<AttackItem> atkItem = std::make_unique<AttackItem>();
};
