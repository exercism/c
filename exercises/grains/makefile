CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror


test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_grains.c src/grains.c src/grains.h
	@echo Compiling $@
	@cc $(CFLAGS) src/grains.c test/vendor/unity.c test/test_grains.c -o tests.out
