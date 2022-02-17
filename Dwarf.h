#pragma once

struct Dwarf : Character
{
    Dwarf(std::string nm, int x, int y);
    std::string getStats() override;
    const std::string& getName() override;

private:
    const std::string name;
};
