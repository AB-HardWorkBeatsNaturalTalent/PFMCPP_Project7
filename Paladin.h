#pragma once
#include <iostream>
#include "Character.h"
struct AttackItem;

struct Paladin : Character
{
    Paladin(std::string nm, int hp, int armor);
    const std::string& getName() override;
    std::string getStats() override;
    void attack(Character& other) override;

private:
    const std::string name;
};

