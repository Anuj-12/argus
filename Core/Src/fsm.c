#include "fsm.h"
#include "rover.h"

transition_t fsm_table[] = {
    // From IDLE
    {IDLE, MOVE_F, FWD, rover_forward},
    {IDLE, MOVE_B, BACK, rover_backward},
    {IDLE, MOVE_L, LEFT, rover_left},
    {IDLE, MOVE_R, RIGHT, rover_right},
    
    // From FWD
    {FWD, STOP, IDLE, rover_stop},
    {FWD, MOVE_B, BACK, rover_backward},
    {FWD, MOVE_L, LEFT, rover_left},
    {FWD, MOVE_R, RIGHT, rover_right},
    
    // From BACK
    {BACK, STOP, IDLE, rover_stop},
    {BACK, MOVE_F, FWD, rover_forward},
    {BACK, MOVE_L, LEFT, rover_left},
    {BACK, MOVE_R, RIGHT, rover_right},
    
    // From LEFT
    {LEFT, STOP, IDLE, rover_stop},
    {LEFT, MOVE_F, FWD, rover_forward},
    {LEFT, MOVE_B, BACK, rover_backward},
    {LEFT, MOVE_R, RIGHT, rover_right},
    
    // From RIGHT
    {RIGHT, STOP, IDLE, rover_stop},
    {RIGHT, MOVE_F, FWD, rover_forward},
    {RIGHT, MOVE_B, BACK, rover_backward},
    {RIGHT, MOVE_L, LEFT, rover_left},
    
    // End marker to stop the iteration
	// 0 works fine as NULL for fxn pointers
    {STATE_INVALID, EVENT_INVALID, STATE_INVALID, 0}
};

rover_state_t fsm_handle_event(rover_state_t curr_state, rover_event_t curr_event){
    for(int i = 0; fsm_table[i].state != STATE_INVALID; i++){
        if(fsm_table[i].state == curr_state && fsm_table[i].event == curr_event){
            if(fsm_table[i].action){
                fsm_table[i].action();
            }

            return fsm_table[i].next_state;
        }
    }

    return curr_state;
}
