#
# Generic makefile for making an example program using the cprocessing library
#
CFLAGS = -g -fPIC

SOURCES= $(wildcard *.cpp)

OBJECTS=$(patsubst %.cpp, %.o, $(SOURCES))

TARGET=$(lastword $(subst /, ,$(realpath .)))

all: $(TARGET)
	@echo $(TARGET) built

$(TARGET): $(OBJECTS)
	@g++ $(CFLAGS) -o $@ $(OBJECTS) -lcprocessing -lglut -lGL -lGLU

clean:
	rm -rf $(OBJECTS) $(TARGET)
