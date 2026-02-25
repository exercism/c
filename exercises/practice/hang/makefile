CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRC = hangman.c test-framework/unity.c hangman_test.c
OUT = test_runner

all: test

test:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)
	./$(OUT)

clean:
	rm -f $(OUT)
