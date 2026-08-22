#include <stdio.h>
#include <assert.h>
#include "../Core/Inc/parser.h"

void rover_forward(void) { printf("Rover: forward\n"); }
void rover_backward(void) { printf("Rover: backward\n"); }
void rover_left(void) { printf("Rover: left\n"); }
void rover_right(void) { printf("Rover: right\n"); }
void rover_stop(void) { printf("Rover: stop\n"); }

#include "../Core/Src/drivers/parser.c"

void test_parse_forward() {
    rover_event_t event = parse_uart_to_event("F\r\n");
    assert(event == MOVE_F);
    printf("OK: test_parse_forward passed\n");
}

void test_parse_backward() {
    rover_event_t event = parse_uart_to_event("B\r\n");
    assert(event == MOVE_B);
    printf("OK: test_parse_backward passed\n");
}

void test_parse_stop() {
    rover_event_t event = parse_uart_to_event("S\r\n");
    assert(event == STOP);
    printf("OK: test_parse_stop passed\n");
}

void test_parse_invalid() {
    rover_event_t event = parse_uart_to_event("GARBAGE\r\n");
    assert(event == EVENT_INVALID);
    printf("OK: test_parse_invalid passed\n");
}

int main() {
    test_parse_forward();
    test_parse_backward();
    test_parse_stop();
    test_parse_invalid();
    printf("\nAll parser tests passed!\n");
    return 0;
}
