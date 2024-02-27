#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../header/Command.h"
#include "../header/CommandHandler.h"
#include "../header/JumpCommand.h"
#include "../header/MoveUnitCommand.h"

class CommandHandlerTest : public ::testing::Test {
};

class MockJumpCommand : public JumpCommand {
public:
    MOCK_METHOD(void, execute, (), (override));
    MOCK_METHOD(void, execute, (GameActor& actor), (override));
    MOCK_METHOD(void, undo, (), (override));
};

class MockMoveUnitCommand : public MoveUnitCommand {
public:
    MockMoveUnitCommand(GameUnit& gameUnit, int x, int y): MoveUnitCommand(gameUnit, x, y) {}

    MOCK_METHOD(void, execute, (), (override));
    MOCK_METHOD(void, execute, (GameActor&), (override));
    MOCK_METHOD(void, undo, (), (override));
};

TEST_F(CommandHandlerTest, ExecutesCommandsInOrderOnReplay) {
    CommandHandler commandHandler;

    GameUnit gameUnit;
    auto jumpCommandPtr = std::make_shared<MockJumpCommand>();
    auto moveUnitCommandPtr = std::make_shared<MockMoveUnitCommand>(gameUnit, 5, 5);

    EXPECT_CALL(*jumpCommandPtr, execute()).Times(2);
    EXPECT_CALL(*moveUnitCommandPtr, execute()).Times(1);

    commandHandler.add(jumpCommandPtr);
    commandHandler.add(moveUnitCommandPtr);
    commandHandler.add(jumpCommandPtr);

    commandHandler.replay();
}