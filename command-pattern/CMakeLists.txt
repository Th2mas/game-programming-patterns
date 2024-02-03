project(command)

set(HEADERS header/Command.h header/JumpCommand.h header/InputHandler.h
        header/VoidCommand.h
        header/GameActor.h
        header/JumpingGameActor.h)
set(SOURCES src/JumpCommand.cpp
        src/InputHandler.cpp
        src/JumpingGameActor.cpp)
set(TESTS tests/JumpCommandTest.cpp
        tests/InputHandlerTest.cpp)

include(GoogleTest)
enable_testing()
add_executable(CommandPatternTest ${TESTS} ${HEADERS} ${SOURCES})
target_link_libraries(CommandPatternTest gtest_main)
gtest_discover_tests(CommandPatternTest)
