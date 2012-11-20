#
# Generic makefile for making an example program using the cprocessing library
#
CFLAGS = -g -fPIC 

SOURCES= $(wildcard *.cpp)

OBJECTS=$(patsubst %.cpp, %.o, $(SOURCES))

TARGET=$(lastword $(subst /, ,$(realpath .)))

all: $(TARGET)
	@echo sketch built

$(TARGET): $(OBJECTS)
	@g++ $(CFLAGS) -o sketch $(OBJECTS) -lcprocessing -lglut -lGL -lGLU -lGLEW

clean:
	rm -rf $(OBJECTS) $(TARGET)
