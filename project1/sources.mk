aring vpath variables
vpath %.c src
vpath %.i preproc
vpath %.o obj

# Listing source files
SRC = main.c memory.c project_1.c

#Preprocessed files
PREPDIR =./
PREP = *.i

ASM_DIR = ./
ASM= *.S

OBJ_DIR = ./
OBJ=*.o
