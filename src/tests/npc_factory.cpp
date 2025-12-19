#include "npc_factory.hpp"

#include "dragon.hpp"
#include "elf.hpp"
#include "druid.hpp"
#include "gtest/gtest.h"

TEST(NPCFactoryTest, CreateDragon) {
    std::shared_ptr<NPC> dragon = NPCFactory::create("Dragon", "Smaug", 10, 20);
    ASSERT_NE(dragon, nullptr);
    EXPECT_EQ(dragon->getType(), "Dragon");
    EXPECT_EQ(dragon->getName(), "Smaug");
    EXPECT_EQ(dragon->getPosition().getX(), 10);
    EXPECT_EQ(dragon->getPosition().getY(), 20);
}

TEST(NPCFactoryTest, CreateElf) {
    std::shared_ptr<NPC> elf = NPCFactory::create("Elf", "Legolas", 5, 15);
    ASSERT_NE(elf, nullptr);
    EXPECT_EQ(elf->getType(), "Elf");
    EXPECT_EQ(elf->getName(), "Legolas");
    EXPECT_EQ(elf->getPosition().getX(), 5);
    EXPECT_EQ(elf->getPosition().getY(), 15);
}

TEST(NPCFactoryTest, CreateDruid) {
    std::shared_ptr<NPC> druid = NPCFactory::create("Druid", "Merlin", 7, 14);
    ASSERT_NE(druid, nullptr);
    EXPECT_EQ(druid->getType(), "Druid");
    EXPECT_EQ(druid->getName(), "Merlin");
    EXPECT_EQ(druid->getPosition().getX(), 7);
    EXPECT_EQ(druid->getPosition().getY(), 14);
}

TEST(NPCFactoryTest, CreateUnknownType) {
    std::shared_ptr<NPC> unknown = NPCFactory::create("Bear", "Baloo", 0, 0);
    EXPECT_EQ(unknown, nullptr);
}

TEST(NPCFactoryTest, FromStringCreatesDragon) {
    std::shared_ptr<NPC> dragonFromString = NPCFactory::fromString("Dragon Smaug 10 20");
    ASSERT_NE(dragonFromString, nullptr);
    EXPECT_EQ(dragonFromString->getType(), "Dragon");
    EXPECT_EQ(dragonFromString->getName(), "Smaug");
    EXPECT_EQ(dragonFromString->getPosition().getX(), 10);
    EXPECT_EQ(dragonFromString->getPosition().getY(), 20);
}

TEST(NPCFactoryTest, FromStringCreatesElf) {
    std::shared_ptr<NPC> elfFromString = NPCFactory::fromString("Elf Legolas 5 15");
    ASSERT_NE(elfFromString, nullptr);
    EXPECT_EQ(elfFromString->getType(), "Elf");
    EXPECT_EQ(elfFromString->getName(), "Legolas");
    EXPECT_EQ(elfFromString->getPosition().getX(), 5);
    EXPECT_EQ(elfFromString->getPosition().getY(), 15);
}

TEST(NPCFactoryTest, FromStringCreatesDruid) {
    std::shared_ptr<NPC> druidFromString = NPCFactory::fromString("Druid Merlin 7 14");
    ASSERT_NE(druidFromString, nullptr);
    EXPECT_EQ(druidFromString->getType(), "Druid");
    EXPECT_EQ(druidFromString->getName(), "Merlin");
    EXPECT_EQ(druidFromString->getPosition().getX(), 7);
    EXPECT_EQ(druidFromString->getPosition().getY(), 14);
}

TEST(NPCFactoryTest, FromStringUnknownType) {
    std::shared_ptr<NPC> unknownFromString = NPCFactory::fromString("Bear Baloo 0 0");
    EXPECT_EQ(unknownFromString, nullptr);
}