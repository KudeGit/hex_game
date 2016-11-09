cmake_minimum_required(VERSION 2.8.9)
project(directory_test)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)

include_directories(../include)
set(COMMON_FLAGS "-W -Wall -Wextra -Werror -g")
if(DEFINED ENV{CPPUTEST_HOME})
    message("Using CppUTest found in $ENV{CPPUTEST_HOME}")
else()
    message("CppUTest library not found")
    return()
endif()

include_directories($ENV{CPPUTEST_HOME}/include)
link_directories($ENV{CPPUTEST_HOME}/lib)

#color
set (sourceColor ../src/color.cpp)
set (sourceTestColor testColor.cpp)
add_executable(testColor test.cpp ${sourceColor} ${sourceTestColor})
target_link_libraries(testColor CppUTest)


#rock
set (sourceColor ../src/color.cpp)
set (sourceRock ../src/rock.cpp)
set (sourceTestRock testRock.cpp)
add_executable(testRock test.cpp ${sourceRock} ${sourceTestRock} ${sourceColor})
target_link_libraries(testRock CppUTest)


#hexboard
set (sourceColor ../src/color.cpp)
set (sourceRock ../src/rock.cpp)
set (sourceHexboard ../src/hexboard.cpp)
set (sourceTestHexboard testHexBoard.cpp)
add_executable(testHexboard test.cpp
    ${sourceRock}
    ${sourceColor}
    ${sourceHexboard}
    ${sourceTestHexboard})
target_link_libraries(testHexboard CppUTest)


#player
set (sourceColor ../src/color.cpp)
set (sourceRock ../src/rock.cpp)
set (sourceHexboard ../src/hexboard.cpp)
set (sourcePlayer ../src/player.cpp)
set (sourceTestPlayer testPlayer.cpp)
add_executable(testPlayer test.cpp
    ${sourceRock}
    ${sourceColor}
    ${sourceHexboard}
    ${sourcePlayer}
    ${sourceTestPlayer})
target_link_libraries(testPlayer CppUTest)


add_executable(all_tests test.cpp ${testColor} ${testRock})
target_link_libraries(all_tests CppUTest)

