#include "dragon.hpp"

#include "elf.hpp"
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

TEST(DragonTest, ConstructorAndGetType) {
    Point point(10, 20);
    Dragon dragon("Smaug", point);
    EXPECT_EQ(dragon.getName(), "Smaug");
    EXPECT_EQ(dragon.getType(), "Dragon");
    EXPECT_EQ(dragon.getPosition().getX(), 10);
    EXPECT_EQ(dragon.getPosition().getY(), 20);
}

TEST(DragonTest, KillsLogic) {
    Point point1(0, 0);
    Dragon dragon1("Smaug", point1);

    Point point2(1, 1);
    Elf elf1("Legolas", point2);
    Druid druid1("Merlin", point2);

    EXPECT_TRUE(dragon1.kills(elf1));      
    EXPECT_FALSE(dragon1.kills(druid1));   
    EXPECT_FALSE(dragon1.kills(dragon1)); 
}

TEST(DragonTest, AcceptVisitor) {
    Point point1(0, 0);
    Dragon dragon1("Smaug", point1);

    Point point2(1, 1);
    Elf elf1("Legolas", point2);

    DummyVisitor visitor1;
    dragon1.accept(visitor1, elf1);

    EXPECT_TRUE(visitor1.visitedDragon);
    EXPECT_FALSE(visitor1.visitedElf);
    EXPECT_FALSE(visitor1.visitedDruid);
}