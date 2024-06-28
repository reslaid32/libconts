cmake_minimum_required(VERSION 3.10)
project(test_project C)

set(CMAKE_C_STANDARD 11)

if(CMAKE_C_COMPILER_ID MATCHES "Clang" OR CMAKE_C_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -g")
elseif(CMAKE_C_COMPILER_ID STREQUAL "MSVC")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /W4 /WX")
endif()

include_directories(libconts)

set(SOURCES
	# main
    main.c
	# libconts
    libconts/hashmap/hashmap.c
    libconts/vector/vector.c
	libconts/list/linked.c
	libconts/list/doubly_linked.c
	libconts/stack/stack.c
	libconts/queue/queue.c
	libconts/deque/deque.c
	libconts/set/set.c
    libconts/tree/binary.c
	# tests
	tests/hashmap.c
    tests/vector.c
	tests/list.c
	tests/stack.c
	tests/queue.c
	tests/deque.c
	tests/set.c
	tests/tree.c
)

add_executable(test ${SOURCES})
