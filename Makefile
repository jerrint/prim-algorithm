P = prim
L = primsAdjacencyList
M = primMatrix

CFLAGS= -Wall -Werror -g -std=c++14

all: $(P)

$(P): $(P).o  $(M).o $(L).o
	g++ $(CFLAGS) $(P).o $(M).o $(L).o -o $(P)
	
$(P).o: $(P).cpp $(L).cpp $(M).cpp
	g++ -c $(CFLAGS) $(P).cpp -o $(P).o 
	
$(L).o: $(L).cpp 
	g++ -c $(CFLAGS) $(L).cpp -o $(L).o 
	
$(M).o: $(M).cpp  
	g++ -c $(CFLAGS) $(M).cpp -o $(M).o 
	
.PHONY: run clean all memcheck

run: all
	./$(P)

clean:
	rm -rf *.o $(P)
	
