MinLeftHeap: main.o Executive.o MinLeftHeap.o Node.o
	g++ -g -std=c++11 main.o Executive.o MinLeftHeap.o Node.o -o MinLeftHeap

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -c main.cpp

Executive.o: Executive.h Executive.cpp MinLeftHeap.h
	g++ -std=c++11 -g -c Executive.cpp

MinLeftHeap.o: MinLeftHeap.h MinLeftHeap.cpp Node.h
	g++ -std=c++11 -g -c MinLeftHeap.cpp

Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -c Node.cpp

clean:
	rm *.o MinLeftHeap
