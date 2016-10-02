CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror


test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_beer_song.c src/beer_song.c src/beer_song.h
	@echo Compiling $@
	@cc $(CFLAGS) src/beer_song.c test/vendor/unity.c test/test_beer_song.c -o tests.out
