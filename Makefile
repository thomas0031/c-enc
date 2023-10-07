# Compiler and compiler flags
CC = gcc
CFLAGS = -Iinclude -Wall -O0 -fno-inline

# Object files
OBJS = main.o include/foo.o

# Target executable
TARGET = main

# Default rule
all: $(TARGET)

# Rule to create the target executable
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

# Rule to create object file from main.c
main.o: main.c include/foo.h
	$(CC) $(CFLAGS) -c main.c

# Rule to create object file from foo.c
include/foo.o: include/foo.c include/foo.h
	$(CC) $(CFLAGS) -c include/foo.c -o include/foo.o

# Rule to clean generated files
clean:
	rm -f $(OBJS) $(TARGET)
