
CC= gcc

CFLAGS= -c -Wall

all: final

final: user.o func.o art.o
	$(CC) user.o func.o art.o -ljson-c -o final

user.o: user.c header.h
	$(CC) $(CFLAGS) user.c 

func.o: func.c header.h
	$(CC) $(CFLAGS) func.c 

art.o: art.c header.h
	$(CC) $(CFLAGS) art.c 

clean:
	rm -rf *o final