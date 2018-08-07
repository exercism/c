CFLAGS  = -std=c99
CFLAGS += -g
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror
CFLAGS += -DUNITY_FLOAT_TYPE=double

VFLAGS  = --quiet
VFLAGS += --tool=memcheck
VFLAGS += --leak-check=full
VFLAGS += --error-exitcode=1

LDFLAGS  = -lm

test: tests.out
	@./tests.out

memcheck: tests.out
	@valgrind $(VFLAGS) ./tests.out
	@echo "Memory check passed"

clean:
	rm -rf *.o *.out *.out.dSYM

tests.out: test/test_complex_numbers.c src/complex_numbers.c src/complex_numbers.h
	@echo Compiling $@
	@$(CC) $(CFLAGS) src/complex_numbers.c test/vendor/unity.c test/test_complex_numbers.c $(LDFLAGS) -o tests.out
