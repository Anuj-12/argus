CC = gcc
CFLAGS = -I../Core/Inc/

TESTS = test_parser test_fsm

all: $(TESTS)

test_parser: test_parser.c 
	$(CC) $(CFLAGS) -o test_parser test_parser.c
	./test_parser

test_fsm: test_fsm.c
	$(CC) $(CFLAGS) -o test_fsm test_fsm.c 
	./test_fsm

clean:
	rm -f $(TESTS)

.PHONY: all clean
