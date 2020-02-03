all: container

container: main.o
	g++ -o $@ main.o
	
main.o: main.cpp Container.h List.h Vector.h
	g++ -c main.cpp

clean: 
	rm container
	rm *.o