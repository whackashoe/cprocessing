CFLAGS = -Wall -g -fPIC

LINKS= `Magick++-config --cppflags --cxxflags --ldflags --libs`

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
	@g++ $(CFLAGS) -c $< -o $@ $(LINKS)

examples:
	$(MAKE) -C examples all
