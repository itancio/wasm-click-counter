CC=gcc
CFLAGS=-std=c11 -ggdb -Wall -Werror -O2 -pedantic
TARGET=testsuite

testsuite: counter_test.c ../../src/counter.c
	$(CC) $(CFLAGS) counter_test.c ../../src/counter.c -o $(TARGET)

.PHONY: clean test

test: testsuite
	./$(TARGET)

clean:
	rm -f $(TARGET)
