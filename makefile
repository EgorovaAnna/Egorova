all: prac

prac: mmap.o Map.o Image.o House.o Position.o Point.o
	g++ -o prac mmap.o Map.o Image.o House.o Position.o Point.o

Map.o: Map.h Map.cpp
	g++ -c Map.cpp Map.h

Image.o: Image.cpp Image.h
	g++ -c Image.cpp Image.h

House.o: House.cpp House.h
	g++ -c House.cpp House.h

Position.o: Position.cpp Position.h
	g++ -c Position.cpp Position.h
	
Point.o: Point.h Point.cpp
	g++ -c Point.cpp Point.h

mmap.o: mmap.cpp
	g++ -c mmap.cpp 
	
clear:
	rm *.o *.gch mapShow.pnm prac
