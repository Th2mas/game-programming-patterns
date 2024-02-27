#ifndef GAMEUNIT_H
#define GAMEUNIT_H

#include <utility>

class GameUnit {
private:
    int x_;
    int y_;
public:
    GameUnit(): GameUnit(0, 0) {}
    GameUnit(int x, int y): x_(x), y_(y) {}
    //  Single-argument constructors must be marked explicit to avoid unintentional implicit conversions
    explicit GameUnit(std::pair<int, int> position): x_(position.first), y_(position.second) {}

    void moveTo(int x, int y) {
        x_ = x;
        y_ = y;
    }

    void moveTo(std::pair<int, int> position) {
        x_ = position.first;
        y_ = position.second;
    }

    int x() const {
        return x_;
    }

    int y() const {
        return y_;
    }
};

#endif //GAMEUNIT_H
