# Specify the version being used as well as the language
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

# Library name
SET(LIB arc)

# Notify cmake of include files
FILE(STRINGS "includes.txt" INC)

# Notify cmake of the source files
FILE(STRINGS "sources.txt" SRC)

# Get list of defines
FILE(STRINGS "defines.txt" DEFS)

MESSAGE("-- Adding definitions")

FOREACH(DEF ${DEFS})

    IF(NOT ${DEF} MATCHES ".*#.*")

        MESSAGE(" -- " ${DEF})
        ADD_DEFINITIONS(-D${DEF})

    ENDIF(NOT ${DEF} MATCHES ".*#.*")

ENDFOREACH(DEF ${DEFS})

# Set compile flags
SET(CMAKE_CXX_FLAGS "-ggdb -Wall -std=c++0x")

SET(Boost_USE_STATIC_LIBS OFF)
SET(Boost_USE_MULTITHREADED ON)
SET(Boost_USE_STATIC_RUNTIME OFF)
FIND_PACKAGE(Boost 1.55.0 COMPONENTS system)

ADD_LIBRARY(
        ${LIB}
        ${SRC}
        ${INC}
)

IF(Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
    TARGET_LINK_LIBRARIES(${LIB} ${Boost_LIBRARIES})
ENDIF(Boost_FOUND)



