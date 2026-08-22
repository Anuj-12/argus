#include <stdio.h>
#include <assert.h>

#include "../Core/Inc/fsm.h"

void rover_forward(void) { printf("Rover: forward\n"); }
void rover_backward(void) { printf("Rover: backward\n"); }
void rover_left(void) { printf("Rover: left\n"); }
void rover_right(void) { printf("Rover: right\n"); }
void rover_stop(void) { printf("Rover: stop\n"); }

#include "../Core/Src/fsm.c"

void test_idle_to_fwd() {
    rover_state_t state = IDLE;
    state = fsm_handle_event(state, MOVE_F);
    assert(state == FWD);
    printf("IDLE + MOVE_F → FWD\n");
}

void test_idle_to_back() {
    rover_state_t state = IDLE;
    state = fsm_handle_event(state, MOVE_B);
    assert(state == BACK);
    printf("IDLE + MOVE_B → BACK\n");
}

void test_idle_to_left() {
    rover_state_t state = IDLE;
    state = fsm_handle_event(state, MOVE_L);
    assert(state == LEFT);
    printf("IDLE + MOVE_L → LEFT\n");
}

void test_idle_to_right() {
    rover_state_t state = IDLE;
    state = fsm_handle_event(state, MOVE_R);
    assert(state == RIGHT);
    printf("IDLE + MOVE_R → RIGHT\n");
}

void test_fwd_to_idle() {
    rover_state_t state = FWD;
    state = fsm_handle_event(state, STOP);
    assert(state == IDLE);
    printf("FWD + STOP → IDLE\n");
}

void test_fwd_to_back() {
    rover_state_t state = FWD;
    state = fsm_handle_event(state, MOVE_B);
    assert(state == BACK);
    printf("FWD + MOVE_B → BACK\n");
}

void test_back_to_idle() {
    rover_state_t state = BACK;
    state = fsm_handle_event(state, STOP);
    assert(state == IDLE);
    printf("BACK + STOP → IDLE\n");
}

void test_back_to_fwd() {
    rover_state_t state = BACK;
    state = fsm_handle_event(state, MOVE_F);
    assert(state == FWD);
    printf("BACK + MOVE_F → FWD\n");
}

void test_invalid_transition() {
    rover_state_t state = IDLE;
    rover_state_t next = fsm_handle_event(state, STOP);
    assert(next == IDLE);  // Invalid, stays same
    printf("IDLE + STOP → IDLE (invalid, stays)\n");
}

void test_fwd_to_left() {
    rover_state_t state = FWD;
    state = fsm_handle_event(state, MOVE_L);
    assert(state == LEFT);
    printf("FWD + MOVE_L → LEFT\n");
}

void test_fwd_to_right() {
    rover_state_t state = FWD;
    state = fsm_handle_event(state, MOVE_R);
    assert(state == RIGHT);
    printf("FWD + MOVE_R → RIGHT\n");
}

void test_back_to_left() {
    rover_state_t state = BACK;
    state = fsm_handle_event(state, MOVE_L);
    assert(state == LEFT);
    printf("BACK + MOVE_L → LEFT\n");
}

void test_back_to_right() {
    rover_state_t state = BACK;
    state = fsm_handle_event(state, MOVE_R);
    assert(state == RIGHT);
    printf("BACK + MOVE_R → RIGHT\n");
}

int main() {
    test_idle_to_fwd();
    test_idle_to_back();
    test_idle_to_left();
    test_idle_to_right();
    test_fwd_to_idle();
    test_fwd_to_back();
    test_fwd_to_left();     
    test_fwd_to_right();     
    test_back_to_idle();
    test_back_to_fwd();
    test_back_to_left();       
    test_back_to_right();     
    test_invalid_transition();
    printf("\nAll FSM tests passed!\n");
    return 0;
}
