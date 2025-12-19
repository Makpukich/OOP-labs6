#include "druid.hpp"
#include "visitor.hpp"

Druid::Druid(const std::string& name, const Point& pos) : NPC(name, pos) {
}

std::string Druid::getType() const {
    return "Druid";
}

bool Druid::kills(const NPC& other) const {
    return other.getType() == "Dragon";
}

void Druid::accept(Visitor& visitor, NPC& other) {
    visitor.visit(*this, other);
}