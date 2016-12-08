CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror

test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_meetup.c src/meetup.c src/meetup.h
	@echo Compiling $@
	@cc $(CFLAGS) src/meetup.c test/vendor/unity.c test/test_meetup.c -o tests.out
