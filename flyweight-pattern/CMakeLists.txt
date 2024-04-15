project(flyweight)

set(HEADERS
        header/Terrain.h
        header/World.h
)
set(SOURCES )
set(TESTS
        tests/WorldTest.cpp
        tests/TerrainTest.cpp)

include(GoogleTest)
enable_testing()
add_executable(FlyweightPatternTest ${TESTS} ${HEADERS} ${SOURCES})
target_link_libraries(FlyweightPatternTest gtest_main gmock_main)
gtest_discover_tests(FlyweightPatternTest)
