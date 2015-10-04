#OBJS specifies which files to compile //battlefield.cpp tiles.cpp battle_entity.cpp battle.cpp projectile.cpp
OBJS = main.cpp

#CC specifies which compiler we're using
CC = g++

#compiler flags
# -w supress warnings
COMPILER_FLAGS = -w -g

#error log
ERROR_LOG = log.txt

#LINKER FLAGS for libraries   -L./BOX2D -lBox2D
LINKER_FLAGS = -lm -L./GENETICS -lGENETICS

#obj name for the name of the exe
OBJ_NAME = PROG

# this is the compile line

all : $(OBJS) 
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME) 2> $(ERROR_LOG) && ./$(OBJ_NAME)