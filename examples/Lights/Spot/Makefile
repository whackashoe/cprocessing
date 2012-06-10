#
# Generic makefile for making an example program using the cprocessing library
#
CFLAGS = -g -fPIC

SOURCES= $(wildcard *.cpp)

OBJECTS=$(patsubst %.cpp, %.o, $(SOURCES))

TARGET=$(lastword $(subst /, ,$(realpath .)))

LINKS= -lcprocessing -lglut -lGLU -lGL

MAGIC = -I/usr/include/ImageMagick -g -O2 -fstack-protector --param=ssp-buffer-size=4 -Wformat -Wformat-security -pthread -L/usr/lib -Wl,-Bsymbolic-functions -Wl,-z,relro -L/usr/lib/X11 -L/usr/lib -lMagick++ -lMagickWand -lMagickCore -llcms -ltiff -lfreetype -ljpeg -llqr-1 -lglib-2.0 -lfontconfig -lXext -lSM -lICE -lX11 -lXt -lbz2 -lz -lm -lgomp -lpthread -lltdl

all: $(TARGET)
	@echo $(TARGET) built

$(TARGET): $(OBJECTS)
	@g++ $(CFLAGS) $(LINKS) -o $@ $(OBJECTS) $(MAGIC)


clean:
	rm -rf $(OBJECTS) $(TARGET)
