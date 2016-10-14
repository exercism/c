CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror

test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_allergies.c src/allergies.c src/allergies.h
	@echo Compiling $@
	@cc $(CFLAGS) src/allergies.c test/vendor/unity.c test/test_allergies.c -o tests.out
