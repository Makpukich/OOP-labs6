#pragma once

class Dragon;
class Elf;
class Druid;
class NPC;

class Visitor {
public:
    virtual ~Visitor() = default;

    virtual void visit(Dragon& attacker, NPC& defender) = 0;
    virtual void visit(Elf& attacker, NPC& defender) = 0;
    virtual void visit(Druid& attacker, NPC& defender) = 0;
};