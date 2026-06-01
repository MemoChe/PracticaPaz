CC = gcc
PKG_CONFIG = pkg-config
CSFML_CFLAGS = $(shell $(PKG_CONFIG) --cflags csfml-graphics)
CSFML_LIBS = $(shell $(PKG_CONFIG) --libs csfml-graphics)
CFLAGS = -Wall -Wextra -std=c11 -I. $(CSFML_CFLAGS)
LDLIBS = $(CSFML_LIBS) -lm

all: testLine

testLine: turtlec.c examples/testLine.c turtlec.h
	$(CC) $(CFLAGS) turtlec.c examples/testLine.c -o testLine $(LDLIBS)

clean:
	rm -f testLine
