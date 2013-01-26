CXXFLAGS=-g -fPIC -ggdb -O3 -std=c++0x -Wall -Weffc++ -pedantic 

OBJDIR=objects

SOURCES= $(wildcard *.cpp)

OBJECTS=$(patsubst %.cpp, $(OBJDIR)/%.o, $(SOURCES))

CC=g++

$(OBJDIR)/libcprocessing.a: $(OBJECTS)
	ar -r $@ $(OBJECTS) 

clean:
	rm -rf $(OBJECTS) $(OBJDIR)/libcprocessing.a

$(OBJDIR)/%.o: %.cpp cprocessing.hpp
	@echo compiling $<
	@$(CC) $(CXXFLAGS) -c $< -o $@
