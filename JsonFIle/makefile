# # this file include 2 file
# # FileFunc.c | FileOPeration.c

# $(CC) = gcc 

# # all: final final1 final2

# final:
# 		$(CC) func.c user.c art.c -ljson-c -o final
# clean:
# 		rm final

CC= gcc

CFLAGS= -c -Wall

all: final

final: user.o func.o art.o
	$(CC) user.o func.o art.o -ljson-c -o final

user.o: user.c header.h
	$(CC) $(CFLAGS) user.c -ljson-c

func.o: func.c header.h
	$(CC) $(CFLAGS) func.c -ljson-c

art.o: art.c header.h
	$(CC) $(CFLAGS) art.c -ljson-c

clean:
	rm -rf *o final