CFLAGS  = -std=c99
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
	@echo "Running memory check"
	@valgrind $(VFLAGS) ./tests.out >> /dev/null
	@echo "Memory check passed"

clean:
	rm -f *.o *.out

tests.out: test/test_hello_world.c src/hello_world.c src/hello_world.h
	@echo Compiling $@
	@cc $(CFLAGS) src/hello_world.c test/vendor/unity.c test/test_hello_world.c -o tests.out
