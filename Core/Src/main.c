#include "stm32f401xe.h"
#include "systick.h"
#include "uart.h"
#include "log.h"
#include "uart_reader.h"
#include "rover.h"
#include "gpio.h"
#include "parser.h"
#include "bluetooth.h"

volatile char msg[50] = {};

int main(){

	rover_init();
	rover_set_speed(100);
	rover_forward();
}
