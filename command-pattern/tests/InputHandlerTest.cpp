#include <gtest/gtest.h>
#include "../header/InputHandler.h"
#include "../header/JumpingGameActor.h"

class InputHandlerTest : public ::testing::Test {
protected:
    InputHandler inputHandler;

    class MockCommand : public Command {
    public:
        bool isPlainExecuteExecuted = false;
        bool isExecuteWithGameActorExecuted = false;

        void execute() override {
            isPlainExecuteExecuted = true;
        }

        void execute(GameActor& actor) override {
            isExecuteWithGameActorExecuted = true;
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
    EXPECT_TRUE(rawPointer->isPlainExecuteExecuted);
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
    EXPECT_FALSE(rawPointer->isPlainExecuteExecuted);
}

TEST_F(InputHandlerTest, ExecutesCommandOnGameActor) {
    // Arrange
    auto mockCommand = std::make_unique<MockCommand>();
    auto rawPointer = mockCommand.get();
    JumpingGameActor actor{};

    inputHandler.bindToButton(BUTTON_B, std::move(mockCommand));

    // Act
    inputHandler.toggleButton(BUTTON_B);
    inputHandler.handleInput(actor);

    // Expect
    EXPECT_FALSE(rawPointer->isPlainExecuteExecuted);
    EXPECT_TRUE(rawPointer->isExecuteWithGameActorExecuted);
}
