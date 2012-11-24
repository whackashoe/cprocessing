CFLAGS = -Wall -g -fPIC -ggdb -O3 

OBJDIR= objects

SOURCES= $(wildcard *.cpp)

OBJECTS=$(patsubst %.cpp, $(OBJDIR)/%.o, $(SOURCES))

$(OBJDIR)/libcprocessing.a: $(OBJECTS)
	ar -r $@ $(OBJECTS) 

clean:
	rm -rf $(OBJECTS) $(OBJDIR)/libcprocessing.a

$(OBJDIR)/%.o: %.cpp cprocessing.hpp
	@echo compiling $<
	@g++ $(CFLAGS) -c $< -o $@
