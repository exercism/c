CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror

test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_all_your_base.c src/all_your_base.c src/all_your_base.h
	@echo Compiling $@
	@cc $(CFLAGS) src/all_your_base.c test/vendor/unity.c test/test_all_your_base.c -o tests.out -lm
