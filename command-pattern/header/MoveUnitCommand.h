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

    void execute() override {
        xBefore_ = unit_.x();
        yBefore_ = unit_.y();
        unit_.moveTo(x_, y_);
    }

    void execute(GameActor& actor) {}

    void undo() override {
        unit_.moveTo(xBefore_, yBefore_);
    }

    int x() const {
        return x_;
    }

    int y() const {
        return y_;
    }

    int xBefore() const {
        return xBefore_;
    }

    int yBefore() const {
        return yBefore_;
    }
};


#endif //MOVEUNITCOMMAND_H
