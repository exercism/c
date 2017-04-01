CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror


test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_wordy.c src/wordy.c src/wordy.h
	@echo Compiling $@
	@cc $(CFLAGS) src/wordy.c test/vendor/unity.c test/test_wordy.c -o tests.out
