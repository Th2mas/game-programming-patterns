#ifndef MOVEUNITCOMMAND_H
#define MOVEUNITCOMMAND_H

#include <memory>
#include "Command.h"
#include "GameUnit.h"


class MoveUnitCommand : public Command {
private:
    GameUnit& unit_;
    int x_;
    int y_;
    int xBefore_;
    int yBefore_;

public:
    MoveUnitCommand(GameUnit& unit, int x, int y): unit_(unit), x_(x), y_(y), xBefore_(0), yBefore_(0) {}
    MoveUnitCommand(GameUnit& unit, std::pair<int, int> position): MoveUnitCommand(unit, position.first, position.second) {}

    void execute() override;
    void execute(GameActor& actor) override;
    void undo() override;

    int x() const;

    int y() const;

    int xBefore() const;

    int yBefore() const;
};


#endif //MOVEUNITCOMMAND_H
