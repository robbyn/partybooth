PROGRAM		= partybooth
VERSION		= 1.2
DEVICE		= attiny13
CLOCK		= 1200000UL
PROGRAMMER	= usbtiny

LDFLAGS	= -Wl,-Map=$(PROGRAM).map -Wl,--cref 

all:	$(PROGRAM).hex

zipsrc:	clean
	 

$(PROGRAM):	all	
	
upload: all
	sudo avrdude -c $(PROGRAMMER) -p $(DEVICE) -U flash:w:partybooth.hex
	
clean:
	rm -f $(PROGRAM).hex $(PROGRAM).elf *.o $(PROGRAM).lst $(PROGRAM).map

%.hex: %.elf
	avr-objcopy -j .text -j .data -O ihex $< $@

$(PROGRAM).elf: main.o
	avr-gcc -g -Wall -Os -DF_CPU=$(CLOCK) -mmcu=$(DEVICE) -o $@ $< $(LDFLAGS)
	avr-size -C --mcu=$(DEVICE) $(PROGRAM).elf

%.o: %.cpp
	avr-g++ -g -Wall -Os -DF_CPU=$(CLOCK) -mmcu=$(DEVICE) -c $< -o $@

disassemble:	$(PROGRAM).elf
	avr-objdump -h -S $(PROGRAM).elf > $(PROGRAM).lst

.PHONY :	all $(PROGRAM) flash fuse install clean disassemble zipsrc
