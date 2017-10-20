FLAGS = -Wall -std=c++11 -g

all: program1 program2 program3

program1:	program1.o 
	g++ $(FLAGS) program1.o  -o program1

program2:	program2.o
	g++ $(FLAGS) program2.o -o program2

program3:	program3.o
	g++ $(FLAGS) program3.o -o program3

program1.o:	program1.cpp	
	g++ $(FLAGS) -c program1.cpp -o program1.o

program2.o:	program2.cpp
	g++ $(FLAGS) -c program2.cpp -o program2.o 

program3.o:	program3.cpp
	g++ $(FLAGS) -c program3.cpp -o program3.o

clean:
	rm -f *.o program1 program2 program3
