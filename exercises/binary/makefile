CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror


test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_binary.c src/binary.c src/binary.h
	@echo Compiling $@
	@cc $(CFLAGS) src/binary.c test/vendor/unity.c test/test_binary.c -o tests.out
