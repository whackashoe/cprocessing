CFLAGS = -Wall -g -fPIC

OBJDIR= objects

SOURCES= $(wildcard *.cpp)

OBJECTS=$(patsubst %.cpp, $(OBJDIR)/%.o, $(SOURCES))

all: $(OBJDIR)/libcprocessing.a

$(OBJDIR)/libcprocessing.a: $(OBJECTS)
	ar -r $@ $(OBJECTS) 

clean:
	rm -rf $(OBJECTS) $(OBJDIR)/libcprocessing.a

$(OBJDIR)/%.o: %.cpp cprocessing.hpp
	@echo compiling $<
	@gcc $(CFLAGS) -c $< -o $@

examples:
	$(MAKE) -C examples all
