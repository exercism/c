CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror


test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_react.c src/react.c src/react.h
	@echo Compiling $@
	@cc $(CFLAGS) src/react.c test/vendor/unity.c test/test_react.c -o tests.out
