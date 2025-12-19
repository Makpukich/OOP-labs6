#include "elf.hpp"

#include "dragon.hpp"
#include "druid.hpp"
#include "gtest/gtest.h"
#include "visitor.hpp"

class DummyVisitor : public Visitor {
   public:
    bool visitedDragon = false;
    bool visitedElf = false;
    bool visitedDruid = false;

    void visit(Dragon& attacker, NPC& defender) override {
        visitedDragon = true;
    }
    void visit(Elf& attacker, NPC& defender) override {
        visitedElf = true;
    }
    void visit(Druid& attacker, NPC& defender) override {
        visitedDruid = true;
    }
};

TEST(ElfTest, ConstructorAndGetType) {
    Point point(15, 25);
    Elf elf("Legolas", point);
    EXPECT_EQ(elf.getName(), "Legolas");
    EXPECT_EQ(elf.getType(), "Elf");
    EXPECT_EQ(elf.getPosition().getX(), 15);
    EXPECT_EQ(elf.getPosition().getY(), 25);
}

TEST(ElfTest, KillsLogic) {
    Point point1(0, 0);
    Elf elf1("Legolas", point1);

    Point point2(1, 1);
    Druid druid1("Merlin", point2);
    Dragon dragon1("Smaug", point2);

    EXPECT_TRUE(elf1.kills(druid1));      
    EXPECT_FALSE(elf1.kills(dragon1));   
    EXPECT_FALSE(elf1.kills(elf1));      
}

TEST(ElfTest, AcceptVisitor) {
    Point point1(0, 0);
    Elf elf1("Legolas", point1);

    Point point2(1, 1);
    Druid druid1("Merlin", point2);

    DummyVisitor visitor1;
    elf1.accept(visitor1, druid1);

    EXPECT_FALSE(visitor1.visitedDragon);
    EXPECT_TRUE(visitor1.visitedElf);
    EXPECT_FALSE(visitor1.visitedDruid);
}