#include "battle_visitor.hpp"

#include "dragon.hpp"
#include "elf.hpp"
#include "druid.hpp"
#include "gtest/gtest.h"
#include "observer.hpp"
#include "point.hpp"

class DummyObserver : public IObserver {
   public:
    std::vector<std::string> messages;

    void onEvent(const std::string& msg) override {
        messages.push_back(msg);
    }
};

TEST(BattleVisitorTest, DragonKillsElf) {
    Point pointDragon(0, 0);
    Point pointElf(10, 10);

    Dragon dragon("Smaug", pointDragon);
    Elf elf("Legolas", pointElf);

    DummyObserver observer;
    BattleVisitor visitor(50.0);
    visitor.addObserver(&observer);

    dragon.accept(visitor, elf);

    ASSERT_EQ(observer.messages.size(), 1);
    EXPECT_EQ(observer.messages[0], "Smaug killed Legolas");
}

TEST(BattleVisitorTest, ElfKillsDruid) {
    Point pointElf(0, 0);
    Point pointDruid(10, 10);

    Elf elf("Legolas", pointElf);
    Druid druid("Merlin", pointDruid);

    DummyObserver observer;
    BattleVisitor visitor(50.0);
    visitor.addObserver(&observer);

    elf.accept(visitor, druid);

    ASSERT_EQ(observer.messages.size(), 1);
    EXPECT_EQ(observer.messages[0], "Legolas killed Merlin");
}

TEST(BattleVisitorTest, DruidKillsDragon) {
    Point pointDruid(0, 0);
    Point pointDragon(10, 10);

    Druid druid("Merlin", pointDruid);
    Dragon dragon("Smaug", pointDragon);

    DummyObserver observer;
    BattleVisitor visitor(50.0);
    visitor.addObserver(&observer);

    druid.accept(visitor, dragon);

    ASSERT_EQ(observer.messages.size(), 1);
    EXPECT_EQ(observer.messages[0], "Merlin killed Smaug");
}

TEST(BattleVisitorTest, MutualKillWhenInRange) {
    Point pointElf(0, 0);
    Point pointDragon(10, 10);

    Elf elf("Legolas", pointElf);
    Dragon dragon("Smaug", pointDragon);

    DummyObserver observer;
    BattleVisitor visitor(50.0);
    visitor.addObserver(&observer);

    dragon.accept(visitor, elf);
    
    ASSERT_EQ(observer.messages.size(), 1);
    EXPECT_EQ(observer.messages[0], "Smaug killed Legolas");
}

TEST(BattleVisitorTest, NoKillOutOfRange) {
    Point pointDragon(0, 0);
    Point pointElf(100, 100);

    Dragon dragon("Smaug", pointDragon);
    Elf elf("Legolas", pointElf);

    DummyObserver observer;
    BattleVisitor visitor(50.0);
    visitor.addObserver(&observer);

    dragon.accept(visitor, elf);

    EXPECT_TRUE(observer.messages.empty());
}