#include <gtest/gtest.h>
#include "../header/MoveUnitCommand.h"

class MoveUnitCommandTest : public ::testing::Test {
};

TEST_F(MoveUnitCommandTest, CorrectlySetsTheValuesInTheConstructor) {
    // Arrange
    int x = 10;
    int y = 15;
    GameUnit unit{};

    // Act
    MoveUnitCommand command{unit, x, y};

    // Assert
    EXPECT_EQ(unit.x(), 0);
    EXPECT_EQ(unit.y(), 0);
    EXPECT_EQ(command.x(), x);
    EXPECT_EQ(command.y(), y);
    EXPECT_EQ(command.xBefore(), 0);
    EXPECT_EQ(command.yBefore(), 0);
}

TEST_F(MoveUnitCommandTest, CorrectlySetsTheValuesAfterExecute) {
    // Arrange
    int xBefore = 5;
    int yBefore = 10;
    int x = 10;
    int y = 15;
    GameUnit unit{xBefore, yBefore};

    // Act
    MoveUnitCommand command{unit, x, y};
    command.execute();

    // Assert
    EXPECT_EQ(unit.x(), x);
    EXPECT_EQ(unit.y(), y);
    EXPECT_EQ(command.x(), x);
    EXPECT_EQ(command.y(), y);
    EXPECT_EQ(command.xBefore(), xBefore);
    EXPECT_EQ(command.yBefore(), yBefore);
}

TEST_F(MoveUnitCommandTest, UndoCorrectlySetsTheOldValues) {
    // Arrange
    int xBefore = 5;
    int yBefore = 10;
    int x = 10;
    int y = 15;
    GameUnit unit{xBefore, yBefore};

    // Act
    MoveUnitCommand command{unit, x, y};
    command.execute();

    // Assert
    EXPECT_EQ(unit.x(), x);
    EXPECT_EQ(unit.y(), y);
    EXPECT_EQ(command.x(), x);
    EXPECT_EQ(command.y(), y);
    EXPECT_EQ(command.xBefore(), xBefore);
    EXPECT_EQ(command.yBefore(), yBefore);

    command.undo();
    EXPECT_EQ(unit.x(), xBefore);
    EXPECT_EQ(unit.y(), yBefore);
}
