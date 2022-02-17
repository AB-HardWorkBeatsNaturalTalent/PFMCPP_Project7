#pragma once

struct Paladin : Character
{
    Paladin(std::string nm, int x, int y);
    const std::string& getName() override;
    std::string getStats() override;

private:
    const std::string name;
};
