//
// Created by tkhle on 16.04.2024.
//

#ifndef GAME_PROGRAMMING_PATTERNS_ACHIEVEMENTS_H
#define GAME_PROGRAMMING_PATTERNS_ACHIEVEMENTS_H

#include "Observer.h"

enum Achievement {
    FELL_OFF_BRIDGE
};

class Achievements : public Observer {
public:
    void onNotify(const Entity &entity, Event event) override;
    virtual void unlock(Achievement achievement);
};

#endif //GAME_PROGRAMMING_PATTERNS_ACHIEVEMENTS_H
