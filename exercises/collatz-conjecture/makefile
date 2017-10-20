CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror

test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_collatz_conjecture.c src/collatz_conjecture.c src/collatz_conjecture.h
	@echo Compiling $@
	@cc $(CFLAGS) src/collatz_conjecture.c test/vendor/unity.c test/test_collatz_conjecture.c -o tests.out
