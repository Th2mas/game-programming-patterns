project(observer)

set(HEADERS header/Observer.h header/Entity.h header/Event.h
        header/Achievements.h
        header/Subject.h)
set(SOURCES
        src/Achievements.cpp
        src/Subject.cpp)
set(TESTS
        tests/AchievementsTest.cpp
        tests/SubjectTest.cpp)

include(GoogleTest)
enable_testing()
add_executable(ObserverPatternTest ${TESTS} ${HEADERS} ${SOURCES})
target_link_libraries(ObserverPatternTest gtest_main gmock_main)
gtest_discover_tests(ObserverPatternTest)
