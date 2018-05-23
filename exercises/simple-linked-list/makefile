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
	
tests.out: test/test_simple_linked_list.c src/simple_linked_list.c src/simple_linked_list.h
	@echo Compiling $@
	@$(CC) $(CFLAGS) src/simple_linked_list.c test/vendor/unity.c test/test_simple_linked_list.c -o tests.out