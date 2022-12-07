# File:   Makefile
# Author: H Parkes
# Description: Makefile for AVR project

PROJECT_NAME		:= UCFK4-API
SRC_EXTENSION		:= c
SRC_DIRECTORIES		:= src/system src/drivers src/utilities
INCLUDE_DIRECTORIES := ./include

CC 					:= avr-gcc
OPTIMIZATION_FLAGs	:= -00
DEPENDENCY_FLAGS 	:= -MMD
MMCU 				:= atmega32u2
CFLAGS 				:= -mmcu=$(MMCU) -Os -Wall -Wstrict-prototypes -Wextra -g $(DEPFLAGS) $(foreach Directory,$(INCLUDE_DIRECTORIES),-I$(Directory))

#---------------------------------------------------------------------------------
# MAKE RULES
#---------------------------------------------------------------------------------

SRC_FILES 			:= $(foreach Directory,$(SRC_DIRECTORIES),$(wildcard $(Directory)/*.$(SRC_EXTENSION)))
OBJECT_FILES		:= $(addprefix build/,$(notdir $(SRC_FILES:.$(SRC_EXTENSION)=.o)))
DEPENDENCY_FILES	:= $(patsubst %.$(SRC_EXTENSION),%.d,$(SRC_FILES))


# Default target - Build binary file
all: $(OBJECT_FILES)

# Clean project - Delete all build output
.PHONY: clean
clean:
	rm -r build/*
	#rm $(OBJECT_FILES) $(DEPENDENCY_FILES)
-include $(DEPENDENCY_FILES)

# Compile source files into object files
build/%.o: src/*/%.c
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) $< -o $@
