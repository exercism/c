CFLAGS  = -std=c99
CFLAGS += -g
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror

VFLAGS  = --quiet
VFLAGS += --tool=memcheck
VFLAGS += --leak-check=full
VFLAGS += --error-exitcode=1

test: tests.out
	@./tests.out

memcheck: tests.out
	@valgrind $(VFLAGS) ./tests.out
	@echo "Memory check passed"

clean:
	rm -rf *.o *.out *.out.dSYM

tests.out: test/test_binary_search_tree.c src/binary_search_tree.c src/binary_search_tree.h
	@echo Compiling $@
	@$(CC) $(CFLAGS) src/binary_search_tree.c test/vendor/unity.c test/test_binary_search_tree.c -o tests.out
