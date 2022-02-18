#pragma once

#include "Character.h"
struct DragonSlayer : Character
{
    DragonSlayer(std::string name, int hp, int armor);
    void attack(Character& other) override;
    std::string getStats() override;
    const std::string& getName() override;
    
private:
    const std::string name;
};
