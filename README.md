# Argus

Argus is a bare-metal STM32 rover firmware project that explores how real embedded systems are structured—from peripheral drivers to command processing and motor control—without relying on STM32 HAL.

## Current Features

- FSM driven architecture
- Interrupt driven UART communication
- HC05 Bluetooth integration 
- Parser based bluetooth command handling
- SysTick based blocking and non-blocking delay
- PWM motor control

## Quick Start

1. **Flash firmware** to STM32F401RE
2. **Connect via Bluetooth** (HC05)
3. **Send commands:** F (forward), B (backward), L/R (turn), S (stop)
4. **Run tests:** `cd tests && make all`

## Planned

- ESP-NOW communication layer to replace bluetooth
- Autonomous navigation
- Camera integration

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




No preview is available as of now because of faulty hardware
