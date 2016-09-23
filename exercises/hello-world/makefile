CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror


test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_hello_world.c src/hello_world.c src/hello_world.h
	@echo Compiling $@
	@cc $(CFLAGS) src/hello_world.c test/vendor/unity.c test/test_hello_world.c -o tests.out
