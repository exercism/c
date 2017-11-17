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
	rm -f *.o *.out

tests.out: test/test_roman_numerals.c src/roman_numerals.c src/roman_numerals.h
	@echo Compiling $@
	@cc $(CFLAGS) src/roman_numerals.c test/vendor/unity.c test/test_roman_numerals.c -o tests.out
