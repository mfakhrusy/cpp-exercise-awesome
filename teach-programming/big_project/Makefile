OBJS = main.o OilRent.o
HDRS = OilRent.hpp

CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
EXEC = project

all : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(EXEC)

main.o : main.cpp $(HDRS)
	$(CC) $(CFLAGS) main.cpp

OilRent.o : OilRent.cpp $(HDRS)
	$(CC) $(CFLAGS) OilRent.cpp

clean : 
	\rm *.o $(EXEC)
