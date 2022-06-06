# this file include 2 file
# FileFunc.c | FileOPeration.c

$(CC) = gcc 

final:
		$(CC) admin.c user.c -o final
clean:
		rm  *.o final