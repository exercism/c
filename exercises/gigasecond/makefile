CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wpedantic
CFLAGS += -Werror


test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_gigasecond.c src/gigasecond.c src/gigasecond.h
	@echo Compiling $@
	@cc $(CFLAGS) src/gigasecond.c test/vendor/unity.c test/test_gigasecond.c -o tests.out
