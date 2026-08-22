# Argus

Argus is a bare-metal STM32 rover firmware project that explores how real embedded systems are structured—from peripheral drivers to command processing and motor control—without relying on STM32 HAL.

## Current Features

- FSM driven architecture
- Interrupt driven UART communication
- HC05 Bluetooth integration 
- Parser based bluetooth command handling
- SysTick based blocking and non-blocking delay
- PWM motor control

## Planned

- ESP-NOW communication layer to replace bluetooth
- IR based line following autonimity
- CV based autonimity

## Hardware Used

- STM32F401RE Nucleo Board
- L298N Motor Driver
- HC05 Bluetooth Module
- DC motors

## Architecture

```text
         HC05
          |
          v
     USART1 RX ISR
          |
          v
      Ring Buffer
          |
          v
   Superloop Polling
          |
          v
     Line Parser
          |
          v
   Command Decoder
          |
          v
  Motor Control Logic
          |
          v
      PWM Timers
```

## Runtime Model

UART reception is interrupt-driven.

The ISR only:
- receives bytes
- stores them into the ring buffer

The main superloop:
- polls completed messages
- parses commands
- updates motor control state

This separation keeps interrupt execution lightweight.

## Debugging Tools

- USB to TTL converter
- 8 Channel Logic Analyzer
