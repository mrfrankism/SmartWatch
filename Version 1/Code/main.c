#include <avr/io.h>
#include <avr/delay.h>
#include "USART.h"
//#include "oled_lib.h"
/* Main file to control the first version of the OLED watch
	Creator:Franco Baudino
*/

 	//PIN DEFINITIONS

#define LED1 B, 5
#define LED2 B, 6
#define LED3 B, 7

#define BTN1 D, 5
#define BTN2 D, 6
#define BTN3 D, 7



// MACROS
#define PORT(port, pin) (PORT ## port)
#define PIN(port, pin) (pin)
#define DDR(port, pin) (DDR ## port)

#define set_output(io) (DDR(io) |= (1<<PIN(io)))
#define toggle(io) (PORT(io) ^= (1<<PIN(io)))
#define set_low(io) (PORT(io) |= (0<<PIN(io)))
#define set_high(io) (PORT(io) |= (1<<PIN(io)))

//test_UART(): Sends and recieves a byte and lights LEDS PB5 and PB6 when both tests pass
//Status : Code for RX needs to be implemented
void test_UART(void){
//	transmit_byte("A");
	//toggle(LED1);
	//_delay_ms(1000);
	//transmitByte(15);
	//CODE FOR RX TEST GOES HERE
//toggle(LED1);
transmitByte(65);
//_delay_ms(300);
//toggle(LED1);
//_delay_ms(300);
	//toggle(LED1);

}

void test_buttons(void){
	PORTB |= (PIND & (1<<5)) | (PIND & (1<<6)) | (PIND & (1<<7));
}

//test_LEDS: Tests the three onboard LEDs to see if they work
//Status: Done
void test_LEDS(void){
		toggle(LED1);
	//	set_high(LED2);
	//	set_high(LED3);
		_delay_ms(1000);
		toggle(LED1);
	//	set_low(LED2);
	//	set_low(LED3);
		_delay_ms(1000);
}


int main(void){
	//set LEDs to output
	set_output(LED1);
	set_output(LED2);
	set_output(LED3);

	toggle(BTN1); //turn btn1 pullup resistor off
	
	//start serial com for testing
	init_UART();

	while(1){
		//test_LEDS();
		//test_UART();
		//test_LEDS();
		test_buttons();
		//_delay_ms(1000);
		}

	return 0;
}


