project(flyweight)

set(HEADERS )
set(SOURCES )
set(TESTS )

include(GoogleTest)
enable_testing()
add_executable(FlyweightPatternTest ${TESTS} ${HEADERS} ${SOURCES})
target_link_libraries(FlyweightPatternTest gtest_main gmock_main)
gtest_discover_tests(FlyweightPatternTest)
