CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror


test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_clock.c src/clock.c src/clock.h
	@echo Compiling $@
	@cc $(CFLAGS) src/clock.c test/vendor/unity.c test/test_clock.c -o tests.out
