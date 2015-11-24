CC = g++ 
COMPILE  = $(CC) -c -g -std=c++0x
LDFLAGS = 
MAKEEXE = $(CC) 

SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
EXE = test

$(EXE): ${OBJ}
	$(MAKEEXE) $^ $(LDFLAGS) -o $@

%.o: %.cpp
	$(COMPILE) $< -o $@

clean:
	rm -f *.o $(EXE)
