#include "../header/CommandHandler.h"

auto CommandHandler::add(const std::shared_ptr<Command>& command) -> void {
    commands.push_back(command);
}

auto CommandHandler::replay() -> void {
    for (auto& command : commands) {
        command->execute();
    }
}
