PROGRAM		= partybooth
DEVICE		= attiny13
CLOCK		= 8000000
PROGRAMMER	= usbtiny
PORT		= usb

# Linker options
LDFLAGS	= -Wl,-Map=$(PROGRAM).map -Wl,--cref 

# symbolic targets:
all:	$(PROGRAM).hex
	avr-size -C --mcu=$(DEVICE) $(PROGRAM).elf

$(PROGRAM):	all	
	
flash: all
	avrdude -c $(PROGRAMMER) -P $(PORT) -p $(DEVICE) -U flash:w:$(PROGRAM).hex:i
	
clean:
	rm -f $(PROGRAM).hex $(PROGRAM).elf *.o $(PROGRAM).lst $(PROGRAM).map

# file targets:
%.hex: %.elf
	avr-objcopy -j .text -j .data -O ihex $< $@
	
$(PROGRAM).elf: main.o
	avr-gcc -g -Wall -Os -DF_CPU=$(CLOCK) -mmcu=$(DEVICE) -o $@ $< $(LDFLAGS)

%.o: %.c
	avr-gcc -g -Wall -Os -DF_CPU=$(CLOCK) -mmcu=$(DEVICE) -c $< -o $@

%.o: %.cpp
	avr-g++ -g -Wall -Os -DF_CPU=$(CLOCK) -mmcu=$(DEVICE) -c $< -o $@

# Targets for code debugging and analysis:
disasm:	$(PROGRAM).elf
	avr-objdump -h -S $(PROGRAM).elf > $(PROGRAM).lst

# Tell make that these targets don't correspond to actual files
.PHONY :	all $(PROGRAM) flash fuse install clean disasm
