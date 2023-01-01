# Name: Mandy Meindersma
# One Card Number: 1433871
# UNIX ID: meinders
# Lecture: A1
# Lab: D01
# TA's Name: Chenyang Huang

lander: lander.o parse.o Testcurses.o functions.o 
	gcc -Wall -g -std=c99 -o lander lander.o parse.o Testcurses.o functions.o -lm -lcurses

lander.o:  lander.c lander.h 
	gcc -Wall -g -std=c99 -c lander.c

parse.o: parse.c lander.h
	gcc -Wall -g -std=c99 -c parse.c

functions.o:  functions.c lander.h 
	gcc -Wall -g -std=c99 -c functions.c

Testcurses.o:  Testcurses.c lander.h 
	gcc -Wall -g -std=c99 -c Testcurses.c

clean:
	-rm -f -v *.o Testcurses functions lander parse core

