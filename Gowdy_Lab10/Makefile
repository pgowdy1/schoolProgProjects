OBJS = main.o

main: $(OBJS)
	g++ -g -o main $(OBJS)

main.o:	main.cpp BinomialQueue.cpp BinomialQueue.h Node.cpp Node.h LevelOrderQueue.cpp LevelOrderQueue.h
	g++ -Wall -c -g -std=c++11 main.cpp 

clean: 
	rm -f *.o *~ main
