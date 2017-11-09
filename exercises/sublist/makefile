CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror

test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_sublist.c src/sublist.c src/sublist.h
	@echo Compiling $@
	@cc $(CFLAGS) src/sublist.c test/vendor/unity.c test/test_sublist.c -o tests.out
