CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror


test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_palindrome_products.c src/palindrome_products.c src/palindrome_products.h
	@echo Compiling $@
	@cc $(CFLAGS) src/palindrome_products.c test/vendor/unity.c test/test_palindrome_products.c -o tests.out
