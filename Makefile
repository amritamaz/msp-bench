####################
# msp-bench makefile
####################

# set your target-mcu! 
TARGETMCU       ?= msp430fr5969
# where is your msp430-include library?
MSP-INCLUDE 	:= /home/amrita/Downloads/msp430-support/include

CROSS           := msp430-elf-
CC              := $(CROSS)gcc
CXX             := $(CROSS)g++
OBJDUMP         := $(CROSS)objdump
SIZE            := $(CROSS)size
LD            	:= $(CC)
LDFLAGS         := -L$(MSP-INCLUDE) -lm
LDFLAGS			+= -I$(MSP-INCLUDE) 
CFLAGS          := -Os -Wall -W -Wextra -mmcu=$(TARGETMCU)
CFLAGS			+= -I$(MSP-INCLUDE) 
CFLAGS			+= -L$(MSP-INCLUDE)

SRCS            := $(wildcard *.c)
# SRCS			:= whet.c
PROG            := $(firstword $(SRCS:.c=))
OBJS            := $(SRCS:.c=.o)
PRGS 			:= $(patsubst %.c,%,$(SRCS))
PRG_SUFFIX 		:=.elf
ELFS 			:= $(patsubst %,%$(PRG_SUFFIX),$(PRGS))
OBJ 			:= $(patsubst %$(PRG_SUFFIX),%.o,$@)


all:            $(ELFS)

%.elf:    %.o
	$(LD) -o $@ $< $(LDFLAGS)

%.o:            %.c
	$(CC) $(CFLAGS) -c $< -Wno-old-style-declaration

%.lst:          %.elf
	$(OBJDUMP) -DS $< > $@
	$(SIZE) $<

clean:
	rm -f $(ELFS).elf $(PRGS).lst $(OBJS)

