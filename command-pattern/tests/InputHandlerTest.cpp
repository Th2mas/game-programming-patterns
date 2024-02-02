#include <gtest/gtest.h>
#include "../header/InputHandler.h"

class InputHandlerTest : public ::testing::Test {
protected:
    InputHandler inputHandler;

    class MockCommand : public Command {
    public:
        bool isExecuted = false;
        void execute() override {
            isExecuted = true;
        }
    };

    void TearDown() override {
        for (auto button : allButtons) {
            if (inputHandler.isPressed(button)) inputHandler.toggleButton(button);
        }
    };
};

TEST_F(InputHandlerTest, ExecutesButtonXCommandOnButtonXPressed) {
    // Arrange
    auto mockCommand = std::make_unique<MockCommand>();
    auto rawPointer = mockCommand.get();

    inputHandler.bindToButton(BUTTON_X, std::move(mockCommand));

    // Act
    inputHandler.toggleButton(BUTTON_X);
    inputHandler.handleInput();

    // Expect
    EXPECT_TRUE(rawPointer->isExecuted);
}

TEST_F(InputHandlerTest, DoesNotExecuteButtonXCommandOnButtonYPressed) {
    // Arrange
    auto mockCommand = std::make_unique<MockCommand>();
    auto rawPointer = mockCommand.get();

    inputHandler.bindToButton(BUTTON_X, std::move(mockCommand));

    // Act
    inputHandler.toggleButton(BUTTON_Y);
    inputHandler.handleInput();

    // Expect
    EXPECT_FALSE(rawPointer->isExecuted);
}
