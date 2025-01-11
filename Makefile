# Compiler and flags
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -g

# Directories
INCLUDE_DIR = libconts
SRC_DIR = .

# Source files
SRC_FILES = \
    $(SRC_DIR)/main.c \
    $(INCLUDE_DIR)/hashmap/hashmap.c \
    $(INCLUDE_DIR)/vector/vector.c \
    $(INCLUDE_DIR)/list/linked.c \
    $(INCLUDE_DIR)/list/doubly_linked.c \
    $(INCLUDE_DIR)/stack/stack.c \
    $(INCLUDE_DIR)/queue/queue.c \
    $(INCLUDE_DIR)/deque/deque.c \
    $(INCLUDE_DIR)/set/set.c \
    $(INCLUDE_DIR)/tree/binary.c \
    $(INCLUDE_DIR)/map/map.c \
    $(SRC_DIR)/tests/hashmap.c \
    $(SRC_DIR)/tests/vector.c \
    $(SRC_DIR)/tests/list.c \
    $(SRC_DIR)/tests/stack.c \
    $(SRC_DIR)/tests/queue.c \
    $(SRC_DIR)/tests/deque.c \
    $(SRC_DIR)/tests/set.c \
    $(SRC_DIR)/tests/tree.c \
    $(SRC_DIR)/tests/map.c

# Output binary
TARGET = test

# Rules
all: $(TARGET)

$(TARGET): $(SRC_FILES)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $^ -o $@

clean:
	rm -f $(TARGET)

.PHONY: all clean
