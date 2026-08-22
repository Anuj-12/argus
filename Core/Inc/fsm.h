#ifndef INC_FSM_H_
#define INC_FSM_H_

typedef enum{
    IDLE,
    FWD,
    BACK,
    LEFT,
    RIGHT,
    STATE_INVALID
}rover_state_t;

typedef enum{
    STOP,
    MOVE_F,
    MOVE_B,
    MOVE_R,
    MOVE_L,
    EVENT_INVALID
}rover_event_t;

typedef struct{
    rover_state_t state;
    rover_event_t event;
    rover_state_t next_state;

    void (*action)(void)
}transition_t;

rover_state_t fsm_handle_event(rover_state_t curr_state, rover_event_t curr_event);

#endif /* INC_FSM_H_ */
