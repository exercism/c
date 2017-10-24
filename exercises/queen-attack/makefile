CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror

test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_queen_attack.c src/queen_attack.c src/queen_attack.h
	@echo Compiling $@
	@cc $(CFLAGS) src/queen_attack.c test/vendor/unity.c test/test_queen_attack.c -o tests.out
