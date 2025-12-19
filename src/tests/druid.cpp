#include "druid.hpp"

#include "dragon.hpp"
#include "elf.hpp"
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

TEST(DruidTest, ConstructorAndGetType) {
    Point point(5, 30);
    Druid druid("Merlin", point);
    EXPECT_EQ(druid.getName(), "Merlin");
    EXPECT_EQ(druid.getType(), "Druid");
    EXPECT_EQ(druid.getPosition().getX(), 5);
    EXPECT_EQ(druid.getPosition().getY(), 30);
}

TEST(DruidTest, KillsLogic) {
    Point point1(0, 0);
    Druid druid1("Merlin", point1);

    Point point2(1, 1);
    Dragon dragon1("Smaug", point2);
    Elf elf1("Legolas", point2);

    EXPECT_TRUE(druid1.kills(dragon1));  
    EXPECT_FALSE(druid1.kills(elf1));     
    EXPECT_FALSE(druid1.kills(druid1));  
}

TEST(DruidTest, AcceptVisitor) {
    Point point1(0, 0);
    Druid druid1("Merlin", point1);

    Point point2(1, 1);
    Dragon dragon1("Smaug", point2);

    DummyVisitor visitor1;
    druid1.accept(visitor1, dragon1);

    EXPECT_FALSE(visitor1.visitedDragon);
    EXPECT_FALSE(visitor1.visitedElf);
    EXPECT_TRUE(visitor1.visitedDruid);
}