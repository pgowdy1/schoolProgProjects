OBJS = main.o

main: $(OBJS)
	g++ -g -o main $(OBJS)

main.o:	main.cpp HashTable.cpp HashTable.h HashList.cpp HashList.h
	g++ -Wall -c -g main.cpp 

clean: 
	rm -f *.o *~ main
