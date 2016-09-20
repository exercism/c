CFLAGS = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror

test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_rna_transcription.c src/rna_transcription.c src/rna_transcription.h
	@echo Compiling $@
	@cc $(CFLAGS) src/rna_transcription.c test/vendor/unity.c test/test_rna_transcription.c -o tests.out
