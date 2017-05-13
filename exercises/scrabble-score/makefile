CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror


test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_scrabble_score.c src/scrabble_score.c src/scrabble_score.h
	@echo Compiling $@
	@cc $(CFLAGS) src/scrabble_score.c test/vendor/unity.c test/test_scrabble_score.c -o tests.out
