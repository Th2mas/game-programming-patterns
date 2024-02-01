project(command)

set(HEADERS header/Command.h header/JumpCommand.h)
set(SOURCES src/JumpCommand.cpp)
set(TESTS tests/JumpCommandTest.cpp)

include(GoogleTest)
enable_testing()
add_executable(CommandPatternTest ${TESTS} ${HEADERS} ${SOURCES})
target_link_libraries(CommandPatternTest gtest_main)
gtest_discover_tests(CommandPatternTest)
