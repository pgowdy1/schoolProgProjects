OBJS = main.o

main: $(OBJS)
	g++ -g -o main $(OBJS)

main.o:	main.cpp SkewHeap.cpp Timer.cpp LeftistHeap.cpp
	g++ -Wall -c -g main.cpp 

clean: 
	rm -f *.o *~ main
