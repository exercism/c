CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror


test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_phone_number.c src/phone_number.c src/phone_number.h
	@echo Compiling $@
	@cc $(CFLAGS) src/phone_number.c test/vendor/unity.c test/test_phone_number.c -o tests.out
