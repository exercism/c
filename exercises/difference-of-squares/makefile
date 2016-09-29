CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror


test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_difference_of_squares.c src/difference_of_squares.c src/difference_of_squares.h
	@echo Compiling $@
	@cc $(CFLAGS) src/difference_of_squares.c test/vendor/unity.c test/test_difference_of_squares.c -o tests.out
