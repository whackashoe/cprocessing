#
# Generic makefile for making an example program using the cprocessing library
#
CFLAGS = -g -fPIC

SOURCES= $(wildcard *.cpp)

OBJECTS=$(patsubst %.cpp, %.o, $(SOURCES))

TARGET=$(lastword $(subst /, ,$(realpath .)))

LINKS= -lcprocessing -lglut -lGLU -lGL

all: $(TARGET)
	@echo $(TARGET) built

$(TARGET): $(OBJECTS)
	@g++ $(CFLAGS) $(LINKS) -o $@ $(OBJECTS)

clean:
	rm -rf $(OBJECTS) $(TARGET)
