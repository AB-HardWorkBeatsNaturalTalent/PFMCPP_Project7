#pragma once

#include "Character.h"
struct Dwarf : Character
{
    Dwarf(std::string name, int hp, int armor);
    std::string getStats() override;
    const std::string& getName() override;
    void attack(Character& other) override;

private:
    const std::string name;
};
