#include "dragon.hpp"
#include "visitor.hpp"

Dragon::Dragon(const std::string& name, const Point& pos) : NPC(name, pos) {
}

std::string Dragon::getType() const {
    return "Dragon";
}

bool Dragon::kills(const NPC& other) const {
    return other.getType() == "Elf";
}

void Dragon::accept(Visitor& visitor, NPC& other) {
    visitor.visit(*this, other);
}