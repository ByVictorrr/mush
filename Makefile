CC = gcc
CFLAGS = -Wall -ansi -pedantic -g -lm
MAIN = mush
OBJ =  mush.o parseline.o readLongLine.o
UNIX1_VIC = vdelapla@unix1.csc.calpoly.edu
UNIX1_CICI = chxiao@unix1.csc.calpoly.edu

all : $(MAIN)

$(MAIN) : $(OBJ) 
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJ)

mush.o : mush.c 
	$(CC) $(CFLAGS) -c mush.c

parseline.o : parseline.c parseline.h
	$(CC) $(CFLAGS) -c parseline.c

readLongLine.o : readLongLine.c readLongLine.h
	$(CC) $(CFLAGS) -c readLongLine.c

ssh_victor:
	ssh $(UNIX1_VIC)

ssh_cici:
	ssh $(UNIX1_CICI)

grader:
	~getaylor-grader/tryAsgn6 > graded.txt

clean:
	rm *.o $(MAIN) 

