all: prac prac2

prac: mmap.o Map.o Image.o House.o Position.o Point.o
	g++ -o prac1 mmap.o Map.o Image.o House.o Position.o Point.o
	
prac2: mphoto.o Image.o Position.o Point.o Photo.o House.o
	g++ -o prac2 mphoto.o Image.o Position.o Point.o Photo.o House.o -lm
	
mphoto.o: mphoto.cpp
	g++ -c mphoto.cpp
	
Photo.o: Photo.cpp Photo.h
	g++ -c -std=c++11 Photo.cpp Photo.h

Map.o: Map.h Map.cpp
	g++ -c Map.cpp Map.h

Image.o: Image.cpp Image.h
	g++ -c Image.cpp Image.h

House.o: House.cpp House.h
	g++ -c -std=c++11 House.cpp House.h

Position.o: Position.cpp Position.h
	g++ -c Position.cpp Position.h
	
Point.o: Point.h Point.cpp
	g++ -c Point.cpp Point.h

mmap.o: mmap.cpp
	g++ -c mmap.cpp 
	
clear:
	rm *.o *.gch
