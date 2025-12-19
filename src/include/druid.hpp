#pragma once

#include <string>
#include "npc.hpp"

class Druid : public NPC {
public:
    Druid(const std::string& name, const Point& pos);
    std::string getType() const override;
    bool kills(const NPC& other) const override;
    void accept(Visitor& visitor, NPC& other) override;
};