#Target file name
TARGET= main hw1

vpath %.c ./src
vpath %.i .
vpath %.S .
vpath %.o .
vpath %.h ./hdr


#Listing C source files
SRC= ./src/*.c

#Object files
#OBJ= $(patsubst %.i,%.o,$(PREP))
OBJ= ./*.o
#Preprocssed output files
PREP= ./*.i

#Assembly files
ASM= ./*.S


#Linker options
# -WI... direct GCC to pass to linker.
#   -Map:     creating map file
#    --cref: adding cross reference to the map file
#LDFLAGS=-Wl,-Map=$(TARGET).map

#Compiler Options

# -g*: generate debugging information
# -O*: optimization level(0 means off and it is upto 3, s means optimize for size)
#-Wall: warning level
CFLAGS = -g -Wall -O0 -std=gnu99

#Define programs and commands
CC = gcc
OBJDUMP = objdump -d 
REMOVE = rm -rf

# Define all object files.
#OBJ = $(SRC:%.c=$(OBJDIR)/%.o) $(ASRC:%.S=$(OBJDIR)/%.o) 

#Define all listing files.
#LST = $(SRC:%.c=$(OBJDIR)/%.lst) $(ASRC:%.S=$(OBJDIR)/%.lst) 


# Compiler flags to generate dependency files.
#GENDEPFLAGS = -MMD -MP -MF .dep/$(@F).d


.PHONY: compile-all
#Compiling all object files
compile-all: make-file.o
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY:make-file.o
make-file.o: make-file.S
	$(CC) -c $(CFLAGS) $< -o $@


.PHONY:make-file.S
make-file.S: make-file.i
	$(CC) -S $(CFLAGS) $< -o $@

.PHONY:make-file.i
make-file.i: $(SRC)
	$(CC) -E $(CFLAGS) $< -o $@

.PHONY:%.o
#Compiling individual files
%.o: %.S
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY:%.S
#Creating assembler files from C source files
%.S: %.i
	$(CC) -S $(CFLAGS) $< -o $@

.PHONY: %.i
#Creating preprocessed source
%.i: %.c 
	$(CC) -E $(CFLAGS) $< -o $@

.PHONY: build
#compiling all objects and linking
build: 
	$(CC) $(CFLAGS) $(SRC) -o project

.PHONY: upload
#Uploading executable on Beaglebone
upload: $(build)
	@scp ./project root@192.168.7.2:home/debian/bin/esemuk/project1


.PHONY: clean

#Remove all object, preprocessed, assembly and excutables and build output files	
clean:
	$(REMOVE) $(OBJ) $(PREP) $(ASM) project 
