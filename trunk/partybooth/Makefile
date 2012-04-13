PROGRAM		= partybooth
VERSION		= 1.2
DEVICE		= attiny13
CLOCK		= 120000
PROGRAMMER	= usbtiny
PORT		= usb

LDFLAGS	= -Wl,-Map=$(PROGRAM).map -Wl,--cref 

all:	$(PROGRAM).hex
	avr-size -C --mcu=$(DEVICE) $(PROGRAM).elf

$(PROGRAM)-$(VERSION)-src.zip:
	zip 

$(PROGRAM):	all	
	
upload: all
	avrdude -c $(PROGRAMMER) -P $(PORT) -p $(DEVICE) -U flash:w:$(PROGRAM).hex:i
	
clean:
	rm -f $(PROGRAM).hex $(PROGRAM).elf *.o $(PROGRAM).lst $(PROGRAM).map

%.hex: %.elf
	avr-objcopy -j .text -j .data -O ihex $< $@

$(PROGRAM).elf: main.o
	avr-gcc -g -Wall -Os -DF_CPU=$(CLOCK) -mmcu=$(DEVICE) -o $@ $< $(LDFLAGS)

%.o: %.cpp
	avr-g++ -g -Wall -Os -DF_CPU=$(CLOCK) -mmcu=$(DEVICE) -c $< -o $@

disassemble:	$(PROGRAM).elf
	avr-objdump -h -S $(PROGRAM).elf > $(PROGRAM).lst

.PHONY :	all $(PROGRAM) flash fuse install clean disassemble zipsrc
