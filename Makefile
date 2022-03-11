OBJS		= main.o tortue.o
SOURCE	= main.cpp tortue.cpp
HEADER	= tortue.hpp
EXEC		= main
CC			= g++
FLAGS		= -g -c -Wall
LFLAGS	= 

all: $(EXEC)

$(EXEC) : $(OBJS)
	$(CC) -o $(EXEC) $(OBJS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

tortue.o: tortue.cpp tortue.hpp
	$(CC) $(FLAGS) tortue.cpp

clean:
	rm -f $(OBJS) $(EXEC)
	

