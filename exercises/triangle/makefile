CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror


test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_triangle.c src/triangle.c src/triangle.h
	@echo Compiling $@
	@cc $(CFLAGS) src/triangle.c test/vendor/unity.c test/test_triangle.c -o tests.out
