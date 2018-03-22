CFLAGS  = -std=c99
CFLAGS += -g
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror

# http://gcc.gnu.org/bugzilla/show_bug.cgi?id=53119
CFLAGS += -Wno-missing-braces

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

tests.out: test/test_flatten_array.c src/flatten_array.c src/flatten_array.h
	@echo Compiling $@
	@cc $(CFLAGS) src/flatten_array.c test/vendor/unity.c test/test_flatten_array.c -o tests.out
