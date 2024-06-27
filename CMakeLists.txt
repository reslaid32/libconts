cmake_minimum_required(VERSION 3.10)
project(test_project C)

set(CMAKE_C_STANDARD 11)

if(CMAKE_C_COMPILER_ID MATCHES "Clang" OR CMAKE_C_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -g")
elseif(CMAKE_C_COMPILER_ID STREQUAL "MSVC")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /W4 /WX")
endif()

include_directories(libconts/hashmap libconts/vector)

set(SOURCES
    main.c
    libconts/hashmap/hashmap.c
    libconts/vector/vector.c
    tests/hashmap.c
    tests/vector.c
)

add_executable(test ${SOURCES})
