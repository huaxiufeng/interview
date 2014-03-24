CC = g++
LDFLAGS = 
MAKEEXE = $(CC) -g

SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
ALL = template string_compress my2d_alloc

all: $(ALL)

template: template.o
	$(MAKEEXE) $^ $(LDFLAGS) -o $@

string_compress: string_compress.o
	$(MAKEEXE) $^ $(LDFLAGS) -o $@

my2d_alloc: my2d_alloc.o
	$(MAKEEXE) $^ $(LDFLAGS) -o $@

%.o: %.cpp
	$(COMPILE.C) $< -o $@

clean:
	rm -f *.o $(ALL)
