//
// Created by tkhle on 16.04.2024.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../header/Achievements.h"

class AchievementsMock : public Achievements {
public:
    MOCK_METHOD(void, unlock, (Achievement), (override));
};

class AchievementsTest : public ::testing::Test {
protected:
    AchievementsMock achievements;
    Entity heroOnBridge{true, true};
    Entity citizenOnBridge{false, true};
};

TEST_F(AchievementsTest, OnNotifyWithHeroAndFellOffBridgeEventTriggersFellOffUnlock) {
    // Arrange and assert
    EXPECT_CALL(achievements, unlock(Achievement::FELL_OFF_BRIDGE))
        .Times(1);

    // Act
    achievements.onNotify(heroOnBridge, EVENT_ENTITY_FELL);
}

TEST_F(AchievementsTest, OnNotifyWithNonHeroAndFellOffBridgeEventDoesNotTriggerFellOffUnlock) {
    // Arrange and assert
    EXPECT_CALL(achievements, unlock(Achievement::FELL_OFF_BRIDGE))
            .Times(0);

    // Act
    achievements.onNotify(citizenOnBridge, EVENT_ENTITY_FELL);
}

TEST_F(AchievementsTest, OnNotifyWithHeroAndNonFellOffBridgeEventDoesNotTriggerFellOffUnlock) {
    // Arrange and assert
    EXPECT_CALL(achievements, unlock(Achievement::FELL_OFF_BRIDGE))
            .Times(0);

    // Act
    achievements.onNotify(heroOnBridge, EVENT_OTHER);
}
