# Makefile for tests directory
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I../libft

# Main library
LIBFT = ../libft/libft.a

# Test source files
BONUS_TEST_SRC = $(wildcard test_ft_lst*_bonus.c)
REGULAR_TEST_SRC = $(filter-out $(BONUS_TEST_SRC), $(wildcard test_*.c))

# Executables
MAIN_REGULAR = test_main
MAIN_BONUS = test_bonus
MAIN_ALL = test_all

# Default rule - runs regular tests only
all: $(MAIN_REGULAR)

# Rule to compile regular tests only
$(MAIN_REGULAR): $(REGULAR_TEST_SRC) $(LIBFT)
	$(CC) $(CFLAGS) -DREGULAR_ONLY $(REGULAR_TEST_SRC) -L../libft -lbsd -lft -o $(MAIN_REGULAR)

# Rule to compile bonus tests only
$(MAIN_BONUS): $(BONUS_TEST_SRC) $(LIBFT)
	$(CC) $(CFLAGS) -DBONUS_ONLY $(BONUS_TEST_SRC) -L../libft -lbsd -lft -o $(MAIN_BONUS)

# Rule to compile all tests together
$(MAIN_ALL): $(REGULAR_TEST_SRC) $(BONUS_TEST_SRC) $(LIBFT)
	$(CC) $(CFLAGS) $(REGULAR_TEST_SRC) $(BONUS_TEST_SRC) -L../libft -lbsd -lft -o $(MAIN_ALL)

# Run regular tests only
run: $(MAIN_REGULAR)
	@echo "Running regular tests..."
	./$(MAIN_REGULAR)

# Run bonus tests only
run-bonus: $(MAIN_BONUS)
	@echo "Running bonus tests..."
	./$(MAIN_BONUS)

# Run all tests together
run-all: $(MAIN_ALL)
	@echo "Running all tests (regular + bonus)..."
	./$(MAIN_ALL)

# Build targets without running
bonus: $(MAIN_BONUS)
build-all: $(MAIN_ALL)

# Clean up
clean:
	rm -f $(MAIN_REGULAR) $(MAIN_BONUS) $(MAIN_ALL)

# Rebuild regular tests and run
re: clean all run

# Rebuild bonus tests and run
re-bonus: clean bonus run-bonus

# Rebuild all tests and run
re-all: clean build-all run-all

# Show what files will be compiled
show:
	@echo "Regular test files:"
	@echo "$(REGULAR_TEST_SRC)"
	@echo ""
	@echo "Bonus test files:"
	@echo "$(BONUS_TEST_SRC)"

.PHONY: all bonus build-all run run-bonus run-all clean re re-bonus re-all show
