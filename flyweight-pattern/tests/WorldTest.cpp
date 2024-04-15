//
// Created by tkhle on 15.04.2024.
//
#include <gtest/gtest.h>
#include "../header/World.h"

class WorldTest : public ::testing::Test {
public:
    World world;
protected:
    void SetUp() override {
        world.setTile(1, 2, GRASS);
        world.setTile(4, 3, RIVER);
        world.setTile(6, 5, HILL);
    }
};

TEST_F(WorldTest, GetMovementCostReturnsCorrectValue) {
    EXPECT_EQ(world.getTile(1, 2).getMoveCost(), 1);
    EXPECT_EQ(world.getTile(4, 3).getMoveCost(), 2);
    EXPECT_EQ(world.getTile(6, 5).getMoveCost(), 3);
}
