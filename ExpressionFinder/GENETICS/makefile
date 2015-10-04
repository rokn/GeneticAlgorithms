#GENETICS engine files  //
GENETICS = chromo.cpp genetics.cpp

#GENETICS objects //
GENETICS_OBJS = chromo.o genetics.o

#CC specifies which compiler we're using
CC = g++

#compiler flags
# -w supress warnings
COMPILER_FLAGS = -w -c

#error log
ERROR_LOG = log.txt

#LINKER FLAGS for libraries
#LINKER_FLAGS =


all : $(GENETICS)
	$(CC) $(COMPILER_FLAGS) $(GENETICS) 2> $(ERROR_LOG) && ar rcs libGENETICS.a $(GENETICS_OBJS) && rm *.o && beep