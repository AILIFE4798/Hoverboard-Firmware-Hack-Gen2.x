/*
* This file is part of the hoverboard-firmware-hack-V2 project. The 
* firmware is used to hack the generation 2 board of the hoverboard.
* These new hoverboards have no mainboard anymore. They consist of 
* two Sensorboards which have their own BLDC-Bridge per Motor and an
* ARM Cortex-M3 processor GD32F130C8.
*
* Copyright (C) 2018 Florian Staeblein
* Copyright (C) 2018 Jakob Broemauer
* Copyright (C) 2018 Kai Liebich
* Copyright (C) 2018 Christoph Lehnert
*
* The program is based on the hoverboard project by Niklas Fauth. The 
* structure was tried to be as similar as possible, so that everyone 
* could find a better way through the code.
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#define TODO_PORT GPIOB				// this should be a pin that does no harm if input or output
#define TODO_PIN	GPIO_PIN_15	// B15 is not accessibla on the smaller QFN32 32 pin MCU version


// LED defines
#define LED_GREEN TODO_PIN				// TODO
#define LED_GREEN_PORT TODO_PORT	// TODO
#define LED_ORANGE TODO_PIN				// TODO
#define LED_ORANGE_PORT TODO_PORT	// TODO
#define LED_RED TODO_PIN					// TODO
#define LED_RED_PORT TODO_PORT		// TODO

#define UPPER_LED_PIN TODO_PIN		// TODO
#define UPPER_LED_PORT TODO_PORT	// TODO
#define LOWER_LED_PIN TODO_PIN		// TODO
#define LOWER_LED_PORT TODO_PORT	// TODO

// Mosfet output
// seems to be an ordinary LED output ?
// led.c:91	gpio_bit_write(MOSFET_OUT_PORT, MOSFET_OUT_PIN, counter_Blue >= setValue_Blue ? RESET : SET); 
#define MOSFET_OUT_PIN TODO_PIN		// TODO
#define MOSFET_OUT_PORT TODO_PORT	// TODO

// Brushless Control DC (BLDC) defines
#define TIMER_BLDC_PULLUP	GPIO_PUPD_PULLUP	// robo, based on Herleybob:defines.h
// Channel G
#define RCU_TIMER_BLDC RCU_TIMER0
#define TIMER_BLDC TIMER0
#define TIMER_BLDC_CHANNEL_G TIMER_CH_2
#define TIMER_BLDC_GH_PIN GPIO_PIN_8		// robo, based on Herleybob:defines.h
#define TIMER_BLDC_GH_PORT GPIOA				// robo, based on Herleybob:defines.h
#define TIMER_BLDC_GL_PIN GPIO_PIN_7		// robo, based on Herleybob:defines.h
#define TIMER_BLDC_GL_PORT GPIOA				// robo, based on Herleybob:defines.h
// Channel B
#define TIMER_BLDC_CHANNEL_B TIMER_CH_1
#define TIMER_BLDC_BH_PIN GPIO_PIN_9		// robo, based on Herleybob:defines.h
#define TIMER_BLDC_BH_PORT GPIOA				// robo, based on Herleybob:defines.h
#define TIMER_BLDC_BL_PIN GPIO_PIN_0		// robo, based on Herleybob:defines.h
#define TIMER_BLDC_BL_PORT GPIOB				// robo, based on Herleybob:defines.h
// Channel Y
#define TIMER_BLDC_CHANNEL_Y TIMER_CH_0
#define TIMER_BLDC_YH_PIN GPIO_PIN_10		// robo, based on Herleybob:defines.h
#define TIMER_BLDC_YH_PORT GPIOA				// robo, based on Herleybob:defines.h
#define TIMER_BLDC_YL_PIN GPIO_PIN_1		// robo, based on Herleybob:defines.h
#define TIMER_BLDC_YL_PORT GPIOB				// robo, based on Herleybob:defines.h

// Timer BLDC short circuit emergency shutoff define
// Is initialized here but never used somewhere else in code.
// setup.c:176	gpio_mode_set(TIMER_BLDC_EMERGENCY_SHUTDOWN_PORT , GPIO_MODE_AF, GPIO_PUPD_NONE, TIMER_BLDC_EMERGENCY_SHUTDOWN_PIN);  
#define TIMER_BLDC_EMERGENCY_SHUTDOWN_PIN TODO_PIN	// TODO
#define TIMER_BLDC_EMERGENCY_SHUTDOWN_PORT TODO_PORT		// TODO

// Hall sensor defines
#define HALL_A_PIN GPIO_PIN_8		// robo, based on Herleybob:defines.h A = U ?
#define HALL_A_PORT GPIOB				// robo, based on Herleybob:defines.h A =  U ?
#define HALL_B_PIN GPIO_PIN_12	// robo, based on Herleybob:defines.h B = V ?
#define HALL_B_PORT GPIOA				// robo, based on Herleybob:defines.h B = V ?
#define HALL_C_PIN GPIO_PIN_3		// robo, based on Herleybob:defines.h C = W ?
#define HALL_C_PORT GPIOB				// robo, based on Herleybob:defines.h C = W ?

// Usart master slave defines
//#define USART_MASTERSLAVE USART1	// robo no second uart port yet.
#ifdef USART_MASTERSLAVE
	#define USART_MASTERSLAVE_TX_PIN GPIO_PIN_2		// TODO
	#define USART_MASTERSLAVE_TX_PORT GPIOA				// TODO
	#define USART_MASTERSLAVE_RX_PIN GPIO_PIN_3		// TODO
	#define USART_MASTERSLAVE_RX_PORT GPIOA				// TODO
#endif

// ADC defines
//#define VBATT_PIN	GPIO_PIN_0				// robo, no gpio_mode_set() inHerleybob:setup.c
//#define VBATT_PORT GPIOA						// robo, no gpio_mode_set() inHerleybob:setup.c
#define VBATT_CHANNEL ADC_CHANNEL_17	// robo, based on Herleybob:setup.c: adc_regular_channel_config(2,ADC_CHANNEL_17,ADC_SAMPLETIME_13POINT5);
//#define CURRENT_DC_PIN	GPIO_PIN_1	// robo, no gpio_mode_set() inHerleybob:setup.c
//#define CURRENT_DC_PORT GPIOA				// robo, no gpio_mode_set() inHerleybob:setup.c
#define CURRENT_DC_CHANNEL ADC_CHANNEL_2	// robo, maybe adc_buf_t:adc is potentiometer input

// Self hold defines
// important pin keeps the mosfet open after the on/off button got pushed !
// main.c:306: gpio_bit_write(SELF_HOLD_PORT, SELF_HOLD_PIN, SET); 
// and turns off power on Shutdown:
// main.c:513:	 gpio_bit_write(SELF_HOLD_PORT, SELF_HOLD_PIN, RESET); 
#define SELF_HOLD_PIN TODO_PIN		// TODO
#define SELF_HOLD_PORT TODO_PORT				// TODO

// Button defines
// on/off (POW) push-button. So also a connection (i guess with some smd resistor in between) to a MCU pin.
// main.c:457: if (gpio_input_bit_get(BUTTON_PORT, BUTTON_PIN)) 
#define BUTTON_PIN GPIO_PIN_2			// robo, based on Herleybob:defines.h
#define BUTTON_PORT GPIOB						// robo, based on Herleybob:defines.h

// Usart steer defines
#define USART_STEER_COM USART1					// robo, based on Herleybob:setup.c: usart_config(void)
#define USART_STEER_AF	GPIO_AF_1				// robo, based on Herleybob:setup.c: usart_config(void)
#define USART_STEER_COM_TX_PIN GPIO_PIN_15	// lerwinDE
#define USART_STEER_COM_TX_PORT GPIOA				// lerwinDE
#define USART_STEER_COM_RX_PIN GPIO_PIN_7		// robo, based on Herleybob:setup.c: usart_config(void)
#define USART_STEER_COM_RX_PORT GPIOA				// robo, based on Herleybob:setup.c: usart_config(void)

#ifdef MASTER
// Buzzer defines
#define BUZZER_PIN GPIO_PIN_11		// robo, based on Herleybob:defines.h
#define BUZZER_PORT GPIOA				// robo, based on Herleybob:defines.h

// Charge state defines
// This seems to be a digital input that hast to be high in order to enable the motors. 
// main.c:381: chargeStateLowActive = gpio_input_bit_get(CHARGE_STATE_PORT, CHARGE_STATE_PIN);
// If not found it should be okay to simply comment this line because chargeStateLowActive in initialised as set = true
#define CHARGE_STATE_PIN GPIO_PIN_0		// TODO
#define CHARGE_STATE_PORT GPIOF				// TODO
#endif

// Debug pin defines - seems to be never used in code.
#define DEBUG_PIN TODO_PIN	// TODO
#define DEBUG_PORT TODO_PORT			// TODO

