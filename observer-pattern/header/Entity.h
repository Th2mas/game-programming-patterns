//
// Created by tkhle on 16.04.2024.
//

#ifndef GAME_PROGRAMMING_PATTERNS_ENTITY_H
#define GAME_PROGRAMMING_PATTERNS_ENTITY_H

class Entity {
private:
    bool isHero_ = false;
    bool isOnBridge_ = false;
public:
    Entity(bool isHero, bool isOnBridge): isHero_(isHero), isOnBridge_(isOnBridge) {}

    bool isHero() const {
        return isHero_;
    }

    bool isOnBridge() const {
        return isOnBridge_;
    }
};

#endif //GAME_PROGRAMMING_PATTERNS_ENTITY_H
