CFLAGS=-std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wold-style-definition


test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_pangram.c src/pangram.c src/pangram.h
	@echo Compiling $@
	@cc src/pangram.c test/vendor/unity.c test/test_pangram.c -o tests.out
