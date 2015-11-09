OBJS = main.o

main: $(OBJS)
	g++ -g -o main $(OBJS)

main.o:	main.cpp Node.cpp Node.h BinarySearchTree.cpp BinarySearchTree.h Heap.cpp Heap.h
	g++ -Wall -c -g main.cpp 

clean: 
	rm -f *.o *~ main
