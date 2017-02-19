CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror


test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_space_age.c src/space_age.c src/space_age.h
	@echo Compiling $@
	@cc $(CFLAGS) src/space_age.c test/vendor/unity.c test/test_space_age.c -o tests.out
