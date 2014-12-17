TARGETMCU       ?= msp430fr5969
MCUTYPE		?= sim


CROSS           := msp430-elf-
CC              := $(CROSS)gcc
CXX             := $(CROSS)g++
OBJDUMP         := $(CROSS)objdump
SIZE            := $(CROSS)size
LD            := $(CC)
LDFLAGS         := -L/home/amrita/Downloads/msp430-support/include -lm
LDFLAGS		+= -I/home/amrita/Downloads/msp430-support/include 
CFLAGS          := -Os -Wall -W -Wextra -mmcu=$(TARGETMCU)
CFLAGS		+= -I/home/amrita/Downloads/msp430-support/include 
CFLAGS		+= -L/home/amrita/Downloads/msp430-support/include 

# SRCS            := $(wildcard *.c)
SRCS			:= whet.c
PROG            := $(firstword $(SRCS:.c=))
OBJS            := $(SRCS:.c=.o)

all:            $(PROG).elf $(PROG).lst

$(PROG).elf:    $(OBJS)
	$(LD) -o $(PROG).elf $(OBJS) $(LDFLAGS)

%.o:            %.c
	$(CC) $(CFLAGS) -c $<

%.lst:          %.elf
	$(OBJDUMP) -DS $< > $@
	$(SIZE) $<

clean:
	rm -f $(PROG).elf $(PROG).lst $(OBJS)

install:        $(PROG).elf
	$(MSPDEBUG) -n rf2500 "prog $(PROG).elf"
