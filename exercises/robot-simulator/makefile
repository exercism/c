CFLAGS  = -std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror


test: tests.out
	@./tests.out

clean:
	rm -f *.o *.out

tests.out: test/test_robot_simulator.c src/robot_simulator.c src/robot_simulator.h
	@echo Compiling $@
	@cc $(CFLAGS) src/robot_simulator.c test/vendor/unity.c test/test_robot_simulator.c -o tests.out
