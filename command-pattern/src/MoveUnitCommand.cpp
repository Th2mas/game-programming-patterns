#include "../header/MoveUnitCommand.h"

auto MoveUnitCommand::execute() -> void {
    xBefore_ = unit_.x();
    yBefore_ = unit_.y();
    unit_.moveTo(x_, y_);
}

auto MoveUnitCommand::execute(GameActor& actor) -> void {}

auto MoveUnitCommand::undo() -> void {
    unit_.moveTo(xBefore_, yBefore_);
}

auto MoveUnitCommand::x() const -> int {
    return x_;
}

auto MoveUnitCommand::y() const -> int {
    return y_;
}

auto MoveUnitCommand::xBefore() const -> int {
    return xBefore_;
}

auto MoveUnitCommand::yBefore() const -> int {
    return yBefore_;
}
