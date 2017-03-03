CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror


test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_palindrome.c src/palindrome.c src/palindrome.h
	@echo Compiling $@
	@cc $(CFLAGS) src/palindrome.c test/vendor/unity.c test/test_palindrome.c -o tests.out
