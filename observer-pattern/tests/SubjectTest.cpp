//
// Created by tkhle on 20.04.2024.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../header/Subject.h"

class MockObserver : public Observer {
public:
    MOCK_METHOD(void, onNotify, (const Entity&, Event), (override));
};

class SubjectTest : public ::testing::Test {
protected:
    Subject subject;
    std::shared_ptr<MockObserver> observer1;
    std::shared_ptr<MockObserver> observer2;
    Entity entity{true, true};
    Event event = Event::EVENT_ENTITY_FELL;

    void SetUp() override {
        observer1 = std::make_shared<MockObserver>();
        observer2 = std::make_shared<MockObserver>();

        subject.clear();
    }
};

TEST_F(SubjectTest, NotifyOnAddedObserverCallsObserverOnNotify) {
    // Arrange and assert
    subject.addObserver(observer1);
    subject.addObserver(observer2);

    EXPECT_CALL(*observer1, onNotify(entity, event))
        .Times(1);
    EXPECT_CALL(*observer2, onNotify(entity, event))
            .Times(1);

    subject.notify(entity, event);
}

TEST_F(SubjectTest, NotifyOnRemovedObserverDoesNotCallObserverOnNotify) {
    // Arrange and assert
    subject.addObserver(observer1);
    subject.addObserver(observer2);
    subject.removeObserver(observer2);

    EXPECT_CALL(*observer1, onNotify(entity, event))
            .Times(2);
    EXPECT_CALL(*observer2, onNotify(entity, event))
            .Times(0);

    subject.notify(entity, event);
    subject.notify(entity, event);
}
