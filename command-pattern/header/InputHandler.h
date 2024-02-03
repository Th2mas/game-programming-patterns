#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <memory>
#include <map>
#include "Command.h"

enum Button {
    BUTTON_A,
    BUTTON_B,
    BUTTON_X,
    BUTTON_Y,
};

// Keep a constexpr array for simpler iterations over the Button enum; no runtime overhead, since it is set at compilation time
constexpr Button allButtons[] = { Button::BUTTON_A, Button::BUTTON_B, Button::BUTTON_X, Button::BUTTON_Y };

class InputHandler {
public:
    InputHandler();

    void handleInput();
    void handleInput(GameActor& actor);
    bool isPressed(Button button);

    void bindToButton(Button button, std::unique_ptr<Command> cmd);
    void toggleButton(Button button);
private:
    std::map<Button, bool> buttonStates;
    std::map<Button, std::unique_ptr<Command>> buttons;
};

#endif //INPUTHANDLER_H
