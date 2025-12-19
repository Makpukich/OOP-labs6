#pragma once

#include <string>
#include "npc.hpp"

class Elf : public NPC {
public:
    Elf(const std::string& name, const Point& pos);
    std::string getType() const override;
    bool kills(const NPC& other) const override;
    void accept(Visitor& visitor, NPC& other) override;
};