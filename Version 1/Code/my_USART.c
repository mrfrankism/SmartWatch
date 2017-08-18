#include <avr/io.h>
//My implementation of USART

//#define UBRR1H _SFR_MEM8(0xCD)
//#define UBRR1L _SFR_MEM8(0xCC)

//#define UCSR1C _SFR_MEM8(0xCA)
//#define USBS1 3

//#define UCSR1B _SFR_MEM8(0xC9)
//#define RXCIE1 7//
//#define TXCIE1 6
//#define UDRIE1 5
//#define RXEN1 4
//#define TXEN1 3
//#define UCSZ12 2
//#define F_CPU 8000000
//#define BAUD_RATE 9600
//#define UBRR_VALUE (F_CPU/(16*BAUD_RATE))-1

void init_UART(){
	//Set BAUD rate
	UBRR1 = 12; //51 = Baud Rate is actully aroud 1250
	//UBRR1H = (unsigned char)(UBRR_VALUE>>8);
//	UBRR1L = (unsigned char)(UBRR_VALUE);

	//Enable UART
	//
	UCSR1A = (1<<1); //double speed uart
	UCSR1B = (1<<RXEN1)|(1<<TXEN1);

	//Set bit frame format
	
	UCSR1C =  (0<<USBS1)|(1<<UCSZ11)|(1<<UCSZ10);
}

void transmitByte(unsigned char data){

	//wait for the data register to be clear

	while(!(UCSR1A & (1<<UDRE1)));

	UDR1 = data;
}