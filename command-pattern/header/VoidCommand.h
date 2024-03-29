#ifndef VOIDCOMMAND_H
#define VOIDCOMMAND_H

#include "Command.h"

class VoidCommand : public Command {
public:
    void execute() override {}
    void execute(GameActor& actor) override {}
    void undo() override {}
};

#endif //VOIDCOMMAND_H
