#ifndef GAMEUNIT_H
#define GAMEUNIT_H

class GameUnit {
private:
    int x_;
    int y_;
public:
    GameUnit(): GameUnit(0, 0) {}
    GameUnit(int x, int y): x_(x), y_(y) {}

    void moveTo(int x, int y) {
        x_ = x;
        y_ = y;
    }

    int x() const {
        return x_;
    }

    int y() const {
        return y_;
    }
};

#endif //GAMEUNIT_H
