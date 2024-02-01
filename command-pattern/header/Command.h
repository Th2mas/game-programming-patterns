#ifndef COMMAND_H
#define COMMAND_H

/**
 * An interface, that only has a single method, is most likely used in the command pattern
 * (similarly to @FuntionalInterface in Java)
 */
class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
};

#endif //COMMAND_H
