//
// Created by tkhle on 19.04.2024.
//

#ifndef GAME_PROGRAMMING_PATTERNS_SUBJECT_H
#define GAME_PROGRAMMING_PATTERNS_SUBJECT_H

#include <memory>
#include <vector>
#include "Observer.h"

// Also called the "Observable"
class Subject {
private:
    std::shared_ptr<Observer> head_;
public:
    Subject(): head_(nullptr) {}

    void addObserver(const std::shared_ptr<Observer>& observer);
    void removeObserver(const std::shared_ptr<Observer>& observer);
    void clear();
    void notify(const Entity& entity, Event event);
};

#endif //GAME_PROGRAMMING_PATTERNS_SUBJECT_H
