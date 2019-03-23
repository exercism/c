### If you wish to use extra libraries,
### add their flags in the "LIBS" variable (like we do with "CFLAGS").

###
CFLAGS  = -std=c99
CFLAGS += -g
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror

VFLAGS  = --quiet
VFLAGS += --tool=memcheck
VFLAGS += --leak-check=full
VFLAGS += --error-exitcode=1

test: tests.out
	@./tests.out

memcheck: tests.out
	@valgrind $(VFLAGS) ./tests.out
	@echo "Memory check passed"

clean:
	rm -rf *.o *.out *.out.dSYM

tests.out: test/test_two_fer.c src/two_fer.c src/two_fer.h
	@echo Compiling $@
	@$(CC) $(CFLAGS) src/two_fer.c test/vendor/unity.c test/test_two_fer.c -o tests.out $(LIBS)
