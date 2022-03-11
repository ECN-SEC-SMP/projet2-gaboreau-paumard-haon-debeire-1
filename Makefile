OBJS		= main.o
SOURCE	= main.cpp
HEADER	= 
EXEC		= main
CC			= g++
FLAGS		= -g -c -Wall
LFLAGS	= 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(EXEC) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

clean:
	rm -f $(OBJS) $(EXEC)