CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror


test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_perfect_numbers.c src/perfect_numbers.c src/perfect_numbers.h
	@echo Compiling $@
	@cc $(CFLAGS) src/perfect_numbers.c test/vendor/unity.c test/test_perfect_numbers.c -o tests.out
