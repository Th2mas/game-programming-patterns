//
// Created by tkhle on 01.02.2024.
//

#ifndef JUMPCOMMAND_H
#define JUMPCOMMAND_H
#include "Command.h"

class JumpCommand : public Command {
public:
    void jump();
    void execute() override {
        jump();
    }
};

#endif //JUMPCOMMAND_H
