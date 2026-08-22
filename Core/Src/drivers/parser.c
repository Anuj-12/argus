// Could use DMA for data transfer
#include "rover.h"
#include "string.h"
#include "parser.h"
#include "fsm.h"

rover_event_t parse_uart_to_event(volatile char* msg) {
    if (strcmp("F\r\n", msg) == 0) {
        return MOVE_F;
    } else if (strcmp("B\r\n", msg) == 0) {
        return MOVE_B;
    } else if (strcmp("L\r\n", msg) == 0) {
        return MOVE_L;
    } else if (strcmp("R\r\n", msg) == 0) {
        return MOVE_R;
    } else if (strcmp("S\r\n", msg) == 0) {
        return STOP;
    }
    return EVENT_INVALID;
}
