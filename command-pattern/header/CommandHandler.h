#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

#include <vector>
#include <memory>
#include "Command.h"

class CommandHandler {
private:
    // We need to work with pointers, since a vector cannot directly work with references, i.e. std::vector<Command&> is not possible
    std::vector<std::shared_ptr<Command>> commands;
public:
    void add(const std::shared_ptr<Command>& command);
    void replay();
};

#endif //COMMANDHANDLER_H
