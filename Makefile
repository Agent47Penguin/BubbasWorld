#CC specifies which compiler we're using
CC = g++

#OBJS specifies which files to compile as part of the project
OBJS = src/main.cpp src/game.cpp src/background.cpp

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -I vendors/include

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -L vendors/lib

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -O1 -Wall -std=c++17 -Wno-missing-braces #-w -Wl,-subsystem,windows

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lraylib -lopengl32 -lgdi32 -lwinmm

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = bin/BubbaWorld.exe

#This is the target that compiles our executable
build:
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

run:
	./$(OBJ_NAME)

clean:
	rm $(OBJ_NAME)