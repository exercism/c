CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror


test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_series.c src/series.c src/series.h
	@echo Compiling $@
	@cc $(CFLAGS) src/series.c test/vendor/unity.c test/test_series.c -o tests.out
