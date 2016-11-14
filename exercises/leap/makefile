CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror


test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_leap.c src/leap.c src/leap.h
	@echo Compiling $@
	@cc $(CFLAGS) src/leap.c test/vendor/unity.c test/test_leap.c -o tests.out
