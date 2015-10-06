#AGE engine files  //
AGE = AGE_Core.cpp AGE_Timer.cpp AGE_Rectangle.cpp AGE_Sprite.cpp AGE_SpriteBatch.cpp AGE_Vector.cpp AGE_Animation.cpp AGE_Camera.cpp AGE_Helper.cpp AGE_Keyboard_Input.cpp AGE_Mouse_Input.cpp 

#AGE objects //
AGE_OBJS = AGE_Core.o AGE_Timer.o AGE_Rectangle.o AGE_Sprite.o AGE_SpriteBatch.o AGE_Vector.o AGE_Animation.o AGE_Camera.o AGE_Helper.o AGE_Keyboard_Input.o AGE_Mouse_Input.o

#CC specifies which compiler we're using
CC = g++

#compiler flags
# -w supress warnings
COMPILER_FLAGS = -w -c

#error log
ERROR_LOG = log.txt

#LINKER FLAGS for libraries
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lm -Ilua-5.0.2/include/ -Llua-5.0.2/lib/ -llua


all : $(AGE)
	$(CC) $(COMPILER_FLAGS) $(AGE) $(LINKER_FLAGS) 2> $(ERROR_LOG) && ar rcs libAGE.a $(AGE_OBJS) && rm *.o && beep