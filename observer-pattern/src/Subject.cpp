//
// Created by tkhle on 19.04.2024.
//
#include "../header/Subject.h"

auto Subject::addObserver(const std::shared_ptr<Observer>& observer) -> void {
    observer->next_ = head_;
    head_ = observer;
}

auto Subject::removeObserver(const std::shared_ptr<Observer>& observer) -> void {
    if (head_ == observer) {
        head_ = observer->next_;
        observer->next_ = nullptr;
        return;
    }

    auto current = head_;
    while (current != nullptr) {
        if (current->next_ == observer) {
            current->next_ = observer->next_;
            observer->next_ = nullptr;
            return;
        }

        current = current->next_;
    }
}

auto Subject::clear() -> void {
    head_ = nullptr;
}

auto Subject::notify(const Entity &entity, Event event) -> void {
    auto observer = head_;
    while (observer != nullptr) {
        observer->onNotify(entity, event);
        observer = observer->next_;
    }
}
