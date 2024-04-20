//
// Created by tkhle on 19.04.2024.
//
#include "../header/Subject.h"

auto Subject::addObserver(const std::shared_ptr<Observer>& observer) -> void {
    observers.push_back(observer);
}

auto Subject::removeObserver(const std::shared_ptr<Observer>& observer) -> void {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

auto Subject::clear() -> void {
    observers.clear();
}

auto Subject::notify(const Entity &entity, Event event) -> void {
    for (auto& observer : observers) {
        observer->onNotify(entity, event);
    }
}
