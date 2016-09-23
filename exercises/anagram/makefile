CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror


test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_anagram.c src/anagram.c src/anagram.h
	@echo Compiling $@
	@cc $(CFLAGS) src/anagram.c test/vendor/unity.c test/test_anagram.c -o tests.out
