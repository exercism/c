CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror


test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_atbash_cipher.c src/atbash_cipher.c src/atbash_cipher.h
	@echo Compiling $@
	@cc $(CFLAGS) src/atbash_cipher.c test/vendor/unity.c test/test_atbash_cipher.c -o tests.out
