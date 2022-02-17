#pragma once

#include "Character.h"

struct Dragon : Character
{

    Dragon(std::string nm, int x, int y);
    void attack(Character& other) override;
    const std::string& getName() override;
    std::string getStats();


private:
    const std::string name;
};


