CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror


test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_pascals_triangle.c src/pascals_triangle.c src/pascals_triangle.h
	@echo Compiling $@
	@cc $(CFLAGS) src/pascals_triangle.c test/vendor/unity.c test/test_pascals_triangle.c -o tests.out
