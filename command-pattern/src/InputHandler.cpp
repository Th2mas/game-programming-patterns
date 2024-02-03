#include "../header/InputHandler.h"
#include "../header/VoidCommand.h"

InputHandler::InputHandler() {
    for (auto button : allButtons) {
        buttonStates[button] = false;

        auto voidCommand = std::make_unique<VoidCommand>();
        buttons[button] = std::move(voidCommand);
    }
}

auto InputHandler::handleInput() -> void {
    for (auto button : allButtons) {
        if (isPressed(button)) {
            buttons[button]->execute();
        }
    }
}

auto InputHandler::handleInput(GameActor& actor) -> void {
    for (auto button : allButtons) {
        if (isPressed(button)) {
            buttons[button]->execute(actor);
        }
    }
}

auto InputHandler::isPressed(Button button) -> bool {
    return buttonStates[button];
}

auto InputHandler::bindToButton(Button button, std::unique_ptr<Command> cmd) -> void {
    buttons[button] = std::move(cmd);
}

auto InputHandler::toggleButton(Button button) -> void {
    buttonStates[button] = !buttonStates[button];
}