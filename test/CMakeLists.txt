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

set (sourceColor ../src/color.cpp)
set (sourceTestColor testColor.cpp)
add_executable(testColor test.cpp ${sourceColor} ${sourceTestColor})
target_link_libraries(testColor CppUTest)


#Bring the headers, such as Student.h into the project

#Can manually add the sources using the set command as follows:
#set(SOURCES src/mainapp.cpp src/Student.cpp)


#However, the file(GLOB...) allows for wildcard additions:


#cmake_minimum_required(VERSION 2.8.9 FATAL_ERROR)

