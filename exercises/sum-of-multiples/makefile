CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror

test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_sum_of_multiples.c src/sum_of_multiples.c src/sum_of_multiples.h
	@echo Compiling $@
	@cc $(CFLAGS) src/sum_of_multiples.c test/vendor/unity.c test/test_sum_of_multiples.c -o tests.out
