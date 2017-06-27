CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror

test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_acronym.c src/acronym.c src/acronym.h
	@echo Compiling $@
	@cc $(CFLAGS) src/acronym.c test/vendor/unity.c test/test_acronym.c -o tests.out
