# File:   Makefile
# Author: H Parkes
# Description: Makefile for AVR project

PROJECT_NAME		:= UCFK4-API
SRC_EXTENSION		:= c
SRC_DIRECTORIES		:= src/system src/drivers src/utilities
INCLUDE_DIRECTORIES := ./include

CC 					:= avr-gcc
OPTIMIZATION_FLAGS	:= -00
DEPENDENCY_FLAGS 	:= -MMD
MMCU 				:= atmega32u2
CFLAGS 				:= -mmcu=$(MMCU) -Os -Wall -Wstrict-prototypes -Wextra -g $(DEPENDENCY_FLAGS) $(foreach directory,$(INCLUDE_DIRECTORIES),-I$(directory))

#---------------------------------------------------------------------------------
# MAKE RULES
#---------------------------------------------------------------------------------

API_SRC_FILES 		:= $(foreach directory,$(SRC_DIRECTORIES),$(wildcard $(directory)/*.$(SRC_EXTENSION)))
API_OBJECT_FILES	:= $(addprefix build/,$(notdir $(API_SRC_FILES:.$(SRC_EXTENSION)=.o)))
API_DEP_FILES		:= $(addprefix build/,$(notdir $(API_SRC_FILES:.$(SRC_EXTENSION)=.d)))

TEST_SRC_FILES		:= $(wildcard test/extra-depth-lmao/*.$(SRC_EXTENSION))
TEST_OBJECT_FILES	:= $(addprefix build/,$(notdir $(TEST_SRC_FILES:.$(SRC_EXTENSION)=.o)))
TEST_DEP_FILES		:= $(addprefix build/,$(notdir $(TEST_SRC_FILES:.$(SRC_EXTENSION)=.d)))
TEST_BINARIES		:= $(addprefix build/bin/,$(notdir $(TEST_SRC_FILES:.$(SRC_EXTENSION)=.out)))


# Default target - Build all unit test binary files
all: $(TEST_BINARIES)

# Make specified unit test - Simply specify unit test in command line arguments
$(MAKECMDGOALS): $(findstring build/bin/$(MAKECMDGOALS).out, $(TEST_BINARIES))


# Print out value of specified variables
print:
	@echo $(API_DEP_FILES)
	@echo $(TEST_DEP_FILES)

# Clean project - Delete all build output
clean:
	rm -r build/*

-include $(API_DEP_FILES) $(TEST_DEP_FILES)

build/bin/%.out: build/%.o $(API_OBJECT_FILES)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $^ -o $@

# Compile source files into object files
build/%.o: */*/%.c
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) $< -o $@


.PHONY: clean print $(MAKECMDGOALS)
