#include "npc_factory.hpp"

#include "dragon.hpp"
#include "elf.hpp"
#include "druid.hpp"

std::shared_ptr<NPC> NPCFactory::create(const std::string& type, const std::string& name, int x,
                                        int y) {
    if (type == "Dragon")
        return std::make_shared<Dragon>(name, Point(x, y));
    if (type == "Elf")
        return std::make_shared<Elf>(name, Point(x, y));
    if (type == "Druid")
        return std::make_shared<Druid>(name, Point(x, y));
    return nullptr;
}

std::shared_ptr<NPC> NPCFactory::fromString(const std::string& line) {
    std::stringstream ss(line);
    std::string type, name;
    int x, y;
    ss >> type >> name >> x >> y;
    return create(type, name, x, y);
}