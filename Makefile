# Makefile for tests directory
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I../libft

# Main library
LIBFT = ../libft/libft.a

# Test source files
TEST_SRC = $(wildcard test_*.c)
MAIN = test_main

# Default rule
all: $(MAIN)

# Rule to compile the main test executable
$(MAIN): $(TEST_SRC) $(LIBFT)
	$(CC) $(CFLAGS) $(TEST_SRC) -L../libft -lbsd -lft -o $(MAIN)

# Run all tests
run: $(MAIN)
	@echo "Running tests..."
	./$(MAIN)

# Clean up
clean:
	rm -f $(MAIN)

# Rebuild and run
re: clean all run

.PHONY: all run clean re
