CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror


test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_space-age.c src/space-age.c src/space-age.h
	@echo Compiling $@
	@cc $(CFLAGS) src/space-age.c test/vendor/unity.c test/test_space-age.c -o tests.out
