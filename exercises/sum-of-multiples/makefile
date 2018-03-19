CFLAGS  = -std=c99
CFLAGS += -g
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror

VFLAGS  = --quiet
VFLAGS += --tool=memcheck
VFLAGS += --leak-check=full
VFLAGS += --error-exitcode=1

test: tests.out
	@./tests.out

memcheck: tests.out
	@valgrind $(VFLAGS) ./tests.out
	@echo "Memory check passed"

clean:
	rm -rf *.o *.out *.out.dSYM

tests.out: test/test_sum_of_multiples.c src/sum_of_multiples.c src/sum_of_multiples.h
	@echo Compiling $@
	@$(CC) $(CFLAGS) src/sum_of_multiples.c test/vendor/unity.c test/test_sum_of_multiples.c -o tests.out
