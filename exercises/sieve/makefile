CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror

test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_sieve.c src/sieve.c src/sieve.h
	@echo Compiling $@
	@cc $(CFLAGS) src/sieve.c test/vendor/unity.c test/test_sieve.c -o tests.out -lm
