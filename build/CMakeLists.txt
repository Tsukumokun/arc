# Specify the version being used as well as the language
cmake_minimum_required(VERSION 2.6)

# Library name
set(LIB arc)

# Notify cmake of include files
file(STRINGS "includes.txt" INC)

# Notify cmake of the source files
file(STRINGS "sources.txt" SRC)

# Set compile flags
set(CMAKE_CXX_FLAGS "-ggdb -Wall -std=c++0x")

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.45.0 COMPONENTS system)

add_library(
        ${LIB}
        ${SRC}
        ${INC}
)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(${LIB} ${Boost_LIBRARIES})
endif()



