CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror


test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_nth_prime.c src/nth_prime.c src/nth_prime.h
	@echo Compiling $@
	@cc $(CFLAGS) src/nth_prime.c test/vendor/unity.c test/test_nth_prime.c -o tests.out
