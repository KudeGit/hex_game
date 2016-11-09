cmake_minimum_required(VERSION 2.8.9)
project(directory_test)

set(CMAKE_CXX_STANDARD 14)
message("Build type is: " ${CMAKE_BUILD_TYPE})
if(CMAKE_BUILD_TYPE MATCHES Release)
    message ("setting build to Release")
    set(CMAKE_BUILD_TYPE Release)
else()
    message ("setting build to Debug")
    set(CMAKE_BUILD_TYPE Debug)
endif()



include_directories(include)
set(COMMON_FLAGS "-W -Wall -Wextra -Werror -g")
IF(CMAKE_BUILD_TYPE MATCHES Release)
    message("Relase build.")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMMON_FLAGS}")
    file(GLOB SOURCES "src/*.cpp")
    add_executable(hex ${SOURCES})
ELSEIF(CMAKE_BUILD_TYPE MATCHES Debug)
    message("CPPUTEST_HOME:" $ENV{CPPUTEST_HOME})
    set(BUILD_TYPE_FLAGS " -O0")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMMON_FLAGS} ${BUILD_TYPE_FLAGS}")
    message("Debug build")
    file(GLOB SOURCES "src/*.cpp")
    add_executable(hex ${SOURCES})

    add_subdirectory(test)

ELSE()
    message("Build type not supported")
ENDIF()

#Bring the headers, such as Student.h into the project

#Can manually add the sources using the set command as follows:
#set(SOURCES src/mainapp.cpp src/Student.cpp)


#However, the file(GLOB...) allows for wildcard additions:


#cmake_minimum_required(VERSION 2.8.9 FATAL_ERROR)

