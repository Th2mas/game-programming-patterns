//
// Created by tkhle on 15.04.2024.
//
#include <gtest/gtest.h>
#include "../header/Terrain.h"

class TerrainTest : public ::testing::Test {
public:
    Terrain grass{1, false, GRASS};
    Terrain hill{3, false, HILL};
    Terrain river{2, true, RIVER};
};

TEST_F(TerrainTest, GetMoveCostReturnsTheCorrectValue) {
    EXPECT_EQ(grass.getMoveCost(), 1);
    EXPECT_EQ(hill.getMoveCost(), 3);
    EXPECT_EQ(river.getMoveCost(), 2);
}

TEST_F(TerrainTest, IsWaterReturnsCorrectBool) {
    EXPECT_FALSE(grass.isWater());
    EXPECT_FALSE(hill.isWater());
    EXPECT_TRUE(river.isWater());
}
