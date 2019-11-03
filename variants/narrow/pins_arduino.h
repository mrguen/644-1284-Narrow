/***************************************************|
|            MIGHTYCORE NARROW PINOUT        		    |
|       https://github.com/MCUdude/MightyCore       |
|                                                   |
| An Arduino core for:                              |
| ATmega1284P	                                      |
| ATmega644PA			                                  |
|                                                   |
|***************************************************/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

#if defined(__AVR_ATmega644A__)
  #define __AVR_ATmega644__
#endif

// To suppress
#define NARROW_PINOUT

#define NUM_DIGITAL_PINS          (32)


// PWM pins
#if defined(__AVR_ATmega644P__)
  #define digitalPinHasPWM(p)       ((p) == 3 || (p) == 4 || (p) == 12 || (p) == 13 || (p) == 14 || (p) == 15)
#elif defined(__AVR_ATmega1284P__)
  #define digitalPinHasPWM(p)       ((p) == 3 || (p) == 4 || (p) == 6 || (p) == 7 || (p) == 12 || (p) == 13 || (p) == 14 || (p) == 15)
#endif

// Builtin LED
#define LED_BUILTIN   (7)
static const uint8_t LED = LED_BUILTIN;

// Analog pins
#define PIN_A0 (24)
#define PIN_A1 (25)
#define PIN_A2 (26)
#define PIN_A3 (27)
#define PIN_A4 (28)
#define PIN_A5 (29)
#define PIN_A6 (30)
#define PIN_A7 (31)
static const uint8_t A0 = PIN_A0;
static const uint8_t A1 = PIN_A1;
static const uint8_t A2 = PIN_A2;
static const uint8_t A3 = PIN_A3;
static const uint8_t A4 = PIN_A4;
static const uint8_t A5 = PIN_A5;
static const uint8_t A6 = PIN_A6;
static const uint8_t A7 = PIN_A7;
#define NUM_ANALOG_INPUTS           (8)
#define analogInputToDigitalPin(p)  ((p < NUM_ANALOG_INPUTS) ? (p) + 24 : -1)
#define analogPinToChannel(p)       ((p) < NUM_ANALOG_INPUTS ? (p) : (p) >= 24 ? (p) - 24 : -1)

// SPI
#define PIN_SPI_SS    (4)
#define PIN_SPI_MOSI  (5)
#define PIN_SPI_MISO  (6)
#define PIN_SPI_SCK   (7)
static const uint8_t SS   = PIN_SPI_SS;
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK  = PIN_SPI_SCK;


// i2c
#define PIN_WIRE_SDA  (17)
#define PIN_WIRE_SCL  (16)
static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;


// Interrupts
#define EXTERNAL_NUM_INTERRUPTS     (3)
#define digitalPinToInterrupt(p)    ((p) == 2 ? 2 : ((p) == 10 ? 0 : ((p) == 11 ? 1 : NOT_AN_INTERRUPT)))

// PCINT
#if defined(__AVR_ATmega644P__) || defined(__AVR_ATmega1284P__)
#define digitalPinToPCMSKbit(p) ((p) % 8)
#define digitalPinToPCICR(p)    (((p) >= 0 && (p) < NUM_DIGITAL_PINS) ? (&PCICR) : ((uint8_t *)0))
#define digitalPinToPCICRbit(p) ( (p) <= 7 ? 1 : (p) <= 15 ? 3 : (p) <= 23 ? 2 : 0 )
#define digitalPinToPCMSK(p)  ((p) <= 7 ? &PCMSK1 : (p) <= 15 ? &PCMSK3 : (p) <= 23 ? &PCMSK2 : &PCMSK0)
#endif

#ifdef ARDUINO_MAIN

#define PA 1
#define PB 2
#define PC 3
#define PD 4


// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)
const uint16_t PROGMEM port_to_mode_PGM[] =
{
  NOT_A_PORT,
  (uint16_t) &DDRA,
  (uint16_t) &DDRB,
  (uint16_t) &DDRC,
  (uint16_t) &DDRD,
};

const uint16_t PROGMEM port_to_output_PGM[] =
{
  NOT_A_PORT,
  (uint16_t) &PORTA,
  (uint16_t) &PORTB,
  (uint16_t) &PORTC,
  (uint16_t) &PORTD,
};

const uint16_t PROGMEM port_to_input_PGM[] =
{
  NOT_A_PORT,
  (uint16_t) &PINA,
  (uint16_t) &PINB,
  (uint16_t) &PINC,
  (uint16_t) &PIND,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] =
{
  PB, /* D0 */
  PB,
  PB,
  PB,
  PB,
  PB,
  PB,
  PB,
  PD, /* D8 */
  PD,
  PD,
  PD,
  PD,
  PD,
  PD,
  PD,
  PC, /* D16 */
  PC,
  PC,
  PC,
  PC,
  PC,
  PC,
  PC,
  PA, /* D24 */
  PA,
  PA,
  PA,
  PA,
  PA,
  PA,
  PA,
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] =
{
  _BV(0), /* D0, port B */
  _BV(1),
  _BV(2),
  _BV(3),
  _BV(4),
  _BV(5),
  _BV(6),
  _BV(7),
  _BV(0), /* D8, port D */
  _BV(1),
  _BV(2),
  _BV(3),
  _BV(4),
  _BV(5),
  _BV(6),
  _BV(7),
  _BV(0), /* D16, port C */
  _BV(1),
  _BV(2),
  _BV(3),
  _BV(4),
  _BV(5),
  _BV(6),
  _BV(7),
  _BV(0), /* D24, port A */
  _BV(1),
  _BV(2),
  _BV(3),
  _BV(4),
  _BV(5),
  _BV(6),
  _BV(7),
};


#if defined(__AVR_ATmega644P__)
const uint8_t PROGMEM digital_pin_to_timer_PGM[] =
{
  NOT_ON_TIMER,   /* D0  - PB0 */
  NOT_ON_TIMER,   /* D1  - PB1 */
  NOT_ON_TIMER,   /* D2  - PB2 */
  TIMER0A,        /* D3  - PB3 */
  TIMER0B,        /* D4  - PB4 */
  NOT_ON_TIMER,   /* D5  - PB5 */
  NOT_ON_TIMER,   /* D6  - PB6 */
  NOT_ON_TIMER,   /* D7  - PB7 */
  NOT_ON_TIMER,   /* D8  - PD0 */
  NOT_ON_TIMER,   /* D9  - PD1 */
  NOT_ON_TIMER,   /* D10 - PD2 */
  NOT_ON_TIMER,   /* D11 - PD3 */
  TIMER1B,        /* D12 - PD4 */
  TIMER1A,        /* D13 - PD5 */
  TIMER2B,        /* D14 - PD6 */
  TIMER2A,        /* D15 - PD7 */
  NOT_ON_TIMER,   /* D16 - PC0 */
  NOT_ON_TIMER,   /* D17 - PC1 */
  NOT_ON_TIMER,   /* D18 - PC2 */
  NOT_ON_TIMER,   /* D19 - PC3 */
  NOT_ON_TIMER,   /* D20 - PC4 */
  NOT_ON_TIMER,   /* D21 - PC5 */
  NOT_ON_TIMER,   /* D22 - PC6 */
  NOT_ON_TIMER,   /* D23 - PC7 */
  NOT_ON_TIMER,   /* D24 - PA0 */
  NOT_ON_TIMER,   /* D25 - PA1 */
  NOT_ON_TIMER,   /* D26 - PA2 */
  NOT_ON_TIMER,   /* D27 - PA3 */
  NOT_ON_TIMER,   /* D28 - PA4 */
  NOT_ON_TIMER,   /* D29 - PA5 */
  NOT_ON_TIMER,   /* D30 - PA6 */
  NOT_ON_TIMER    /* D31 - PA7 */
};

#elif defined(__AVR_ATmega1284P__)
const uint8_t PROGMEM digital_pin_to_timer_PGM[] =
{
  NOT_ON_TIMER,   /* D0  - PB0 */
  NOT_ON_TIMER,   /* D1  - PB1 */
  NOT_ON_TIMER,   /* D2  - PB2 */
  TIMER0A,        /* D3  - PB3 */
  TIMER0B,        /* D4  - PB4 */
  NOT_ON_TIMER,   /* D5  - PB5 */
  TIMER3A,        /* D6  - PB6 */
  TIMER3B,        /* D7  - PB7 */
  NOT_ON_TIMER,   /* D8  - PD0 */
  NOT_ON_TIMER,   /* D9  - PD1 */
  NOT_ON_TIMER,   /* D10 - PD2 */
  NOT_ON_TIMER,   /* D11 - PD3 */
  TIMER1B,        /* D12 - PD4 */
  TIMER1A,        /* D13 - PD5 */
  TIMER2B,        /* D14 - PD6 */
  TIMER2A,        /* D15 - PD7 */
  NOT_ON_TIMER,   /* D16 - PC0 */
  NOT_ON_TIMER,   /* D17 - PC1 */
  NOT_ON_TIMER,   /* D18 - PC2 */
  NOT_ON_TIMER,   /* D19 - PC3 */
  NOT_ON_TIMER,   /* D20 - PC4 */
  NOT_ON_TIMER,   /* D21 - PC5 */
  NOT_ON_TIMER,   /* D22 - PC6 */
  NOT_ON_TIMER,   /* D23 - PC7 */
  NOT_ON_TIMER,   /* D24 - PA0 */
  NOT_ON_TIMER,   /* D25 - PA1 */
  NOT_ON_TIMER,   /* D26 - PA2 */
  NOT_ON_TIMER,   /* D27 - PA3 */
  NOT_ON_TIMER,   /* D28 - PA4 */
  NOT_ON_TIMER,   /* D29 - PA5 */
  NOT_ON_TIMER,   /* D30 - PA6 */
  NOT_ON_TIMER    /* D31 - PA7 */
};

#endif // Timer defs

#endif // ARDUINO_MAIN


// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.

#define SERIAL_PORT_MONITOR         Serial
#define SERIAL_PORT_HARDWARE        Serial
#define SERIAL_PORT_HARDWARE_OPEN   Serial

#if defined(__AVR_ATmega644P__) || defined(__AVR_ATmega1284P__)
#define SERIAL_PORT_HARDWARE1       Serial1
#define SERIAL_PORT_HARDWARE_OPEN1  Serial1
#endif

#endif // Pins_Arduino_h
