CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror

test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_isogram.c src/isogram.c src/isogram.h
	@echo Compiling $@
	@cc $(CFLAGS) src/isogram.c test/vendor/unity.c test/test_isogram.c -o tests.out
