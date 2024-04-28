//
// Created by tkhle on 16.04.2024.
//

#ifndef GAME_PROGRAMMING_PATTERNS_OBSERVER_H
#define GAME_PROGRAMMING_PATTERNS_OBSERVER_H

#include <memory>
#include "Entity.h"
#include "Event.h"

class Observer {
    friend class Subject;

    std::shared_ptr<Observer> next_;

public:
    Observer(): next_(nullptr) {}

    virtual ~Observer() = default;
    virtual void onNotify(const Entity& entity, Event event) = 0;
};

#endif //GAME_PROGRAMMING_PATTERNS_OBSERVER_H
