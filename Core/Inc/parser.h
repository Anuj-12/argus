#ifndef INC_PARSER_H_
#define INC_PARSER_H_

#include "fsm.h"

rover_event_t parse_uart_to_event(volatile char* msg);

#endif /* INC_PARSER_H_ */
