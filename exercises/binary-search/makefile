CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror


test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_binary_search.c src/binary_search.c src/binary_search.h
	@echo Compiling $@
	@cc $(CFLAGS) src/binary_search.c test/vendor/unity.c test/test_binary_search.c -o tests.out
