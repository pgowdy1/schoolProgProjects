OBJS = main.o

main: $(OBJS)
	g++ -g -o main $(OBJS)

main.o:	Llist.h Llist.cpp main.cpp Node.cpp Node.h
	g++ -Wall -c -g main.cpp 

clean: 
	rm -f *.o *~ main
