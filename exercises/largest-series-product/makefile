CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror


test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_largest_series_product.c src/largest_series_product.c src/largest_series_product.h
	@echo Compiling $@
	@cc $(CFLAGS) src/largest_series_product.c test/vendor/unity.c test/test_largest_series_product.c -o tests.out
