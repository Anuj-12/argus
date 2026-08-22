#include "stm32f401xe.h"
#include "bluetooth.h"
#include "fsm.h"
#include "rover.h"
#include "bluetooth.h"
#include "uart_reader.h"
#include "parser.h"
#include <string.h>

volatile char msg[50] = {};

int main(){

	rover_init();
	rover_set_speed(100);

	bluetooth_init("Argus", "1234");

	rover_state_t curr_state = IDLE;
	rover_event_t curr_event = EVENT_INVALID;

	while(1){
		uart1_getline(msg);

		curr_event = parse_uart_to_event(msg);
	    curr_state = fsm_handle_event(curr_state, curr_event);

	    memset(msg, 0, sizeof(msg));
	}
}
