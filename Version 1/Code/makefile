#My make file
#OLED Watch MakeFile
CC=avr-gcc
OBJECTS = main.o USART.o oled_lib.o
MCU=atmega32u4
F_CPU = 8000000UL
CFLAGS=-Os -F_CPU=1000000UL -mmcu=${MCU}
PROGRAMMER = usbtiny

all: main.hex

main.hex: main.elf
	avr-objcopy -j .text -j .data -O ihex main.elf main.hex

main.elf: ${OBJECTS}
	${CC} ${CFLAGS} -o main.elf ${OBJECTS}

install:
	#avrdude -v -p ${MCU} -c arduino -P COM4 -b 115200 -D -U flash:w:main.hex
	avrdude -v -c usbtiny -p ${MCU} -U flash:w:main.hex