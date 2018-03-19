CFLAGS = -std=c99
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

tests.out: src/nucleotide_count.c src/nucleotide_count.h test/test_nucleotide_count.c 
	@echo Compiling $@
	@$(CC) $(CFLAGS) src/nucleotide_count.c test/vendor/unity.c test/test_nucleotide_count.c -o tests.out
