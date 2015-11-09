OBJS = main.o

main: $(OBJS)
	g++ -g -o main $(OBJS)

main.o:	main.cpp Heap.cpp Heap.h 
	g++ -Wall -c -g main.cpp 

clean: 
	rm -f *.o *~ main
