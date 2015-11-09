main: Set.o MinSpanningTree.o Main.o
	g++ Set.o MinSpanningTree.o Main.o -o main

Set.o: Set.cpp
	g++ -c -g -std=c++11 Set.cpp

MinSpanningTree.o: MinSpanningTree.cpp
	g++ -c -g -std=c++11 MinSpanningTree.cpp

Main.o: Main.cpp
	g++ -c -g Main.cpp

clean: 
	rm -f *.o *~ main
