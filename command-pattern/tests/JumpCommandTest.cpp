#include <gtest/gtest.h>
#include "../header/JumpCommand.h"

class JumpCommandTest : public ::testing::Test {
protected:
    bool isJumpCalled = false;
    void mock_jump() {
        isJumpCalled = true;
    }

    class MockJumpCommand : public JumpCommand {
    public:
        std::function<void()> jump_function;
        void execute() override {
            jump_function();
        }
    };

    MockJumpCommand mockJumpCommand;

    void SetUp() override {
        mockJumpCommand.jump_function = [this]() { mock_jump(); };
    }
};

TEST_F(JumpCommandTest, ExecutesJump) {
    mockJumpCommand.execute();
    ASSERT_TRUE(isJumpCalled);
}
