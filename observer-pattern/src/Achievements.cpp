//
// Created by tkhle on 16.04.2024.
//
#include "../header/Achievements.h"

auto Achievements::onNotify(const Entity &entity, Event event) -> void {
    switch (event) {
        case EVENT_ENTITY_FELL:
            if (entity.isHero() && entity.isOnBridge()) {
                unlock(Achievement::FELL_OFF_BRIDGE);
            }
            break;
        default:
            break;
    }
}

auto Achievements::unlock(Achievement achievement) -> void {
    // Do something
}
