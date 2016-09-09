CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wpedantic
CFLAGS += -Werror


test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_hamming.c src/hamming.c src/hamming.h
	@echo Compiling $@
	@cc $(CFLAGS) src/hamming.c test/vendor/unity.c test/test_hamming.c -o tests.out
