#ifndef COMMAND_H
#define COMMAND_H

#include "GameActor.h"

/**
 * An interface, that only has a single method, is most likely used in the command pattern
 * (similarly to @FuntionalInterface in Java)
 */
class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
    virtual void execute(GameActor& actor) = 0;
    virtual void undo() = 0;
};

#endif //COMMAND_H
