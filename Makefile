OBJS	= tortue.o carte.o pioche.o joueur.o plateau.o partie.o humain.o ia.o main.o
SOURCE	= tortue.cpp carte.cpp pioche.cpp joueur.cpp plateau.cpp partie.cpp humain.cpp ia.cpp main.cpp
HEADER	= tortue.hpp carte.hpp pioche.hpp joueur.hpp plateau.hpp partie.hpp humain.hpp ia.hpp
OUT	= exec
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

tortue.o: tortue.cpp
	$(CC) $(FLAGS) tortue.cpp 

carte.o: carte.cpp
	$(CC) $(FLAGS) carte.cpp 

pioche.o: pioche.cpp
	$(CC) $(FLAGS) pioche.cpp 

joueur.o: joueur.cpp
	$(CC) $(FLAGS) joueur.cpp

plateau.o: plateau.cpp
	$(CC) $(FLAGS) plateau.cpp

partie.o: partie.cpp
	$(CC) $(FLAGS) partie.cpp

humain.o: humain.cpp
	$(CC) $(FLAGS) humain.cpp

ia.o: ia.cpp
	$(CC) $(FLAGS) ia.cpp

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

clean:
	rm -f $(OBJS)
