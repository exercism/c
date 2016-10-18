CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror


test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_roman_numerals.c src/roman_numerals.c src/roman_numerals.h
	@echo Compiling $@
	@cc $(CFLAGS) src/roman_numerals.c test/vendor/unity.c test/test_roman_numerals.c -o tests.out
