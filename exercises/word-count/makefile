CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror


test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_word_count.c src/word_count.c src/word_count.h
	@echo Compiling $@
	@cc $(CFLAGS) src/word_count.c test/vendor/unity.c test/test_word_count.c -o tests.out
