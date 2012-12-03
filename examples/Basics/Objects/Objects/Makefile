#
# Generic makefile for making an example program using the cprocessing library
#
CXXFLAGS=-O3 -std=c++0x -D_DEBUG -Wall

SOURCES= $(wildcard *.cpp)

OBJECTS=$(patsubst %.cpp, %.o, $(SOURCES))

TARGET=$(lastword $(subst /, ,$(realpath .)))

LINKS=-lcprocessing -lglut -lGL -lGLU -lGLEW -lfreeimage

CC=g++

all: $(TARGET)
	@echo sketch built

$(TARGET): $(OBJECTS)
	@$(CC) $(CXXFLAGS) -o sketch $(OBJECTS) $(LINKS)

clean:
	rm -rf $(OBJECTS) $(TARGET)
