#include "elf.hpp"
#include "visitor.hpp"

Elf::Elf(const std::string& name, const Point& pos) : NPC(name, pos) {
}

std::string Elf::getType() const {
    return "Elf";
}

bool Elf::kills(const NPC& other) const {
    return other.getType() == "Druid";
}

void Elf::accept(Visitor& visitor, NPC& other) {
    visitor.visit(*this, other);
}