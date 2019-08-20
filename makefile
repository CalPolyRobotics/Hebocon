F_CPU = 1000000

MAIN=hebecon.elf

all: $(MAIN)

$(MAIN): hebecon.c define_delay.h
	avr-gcc -mmcu=attiny85 -DF_CPU=$(F_CPU) -Og -o $(MAIN) hebecon.c
	avr-objcopy -O ihex $(MAIN) hebecon.hex
	avr-size hebecon.hex

clean:
	rm -rf *.elf *.o *.hex

flash: $(MAIN)
	avrdude -B 5 -p attiny85 -c stk600 -U flash:w:hebecon.hex 
