# Name: Mandy Meindersma
# One Card Number: 1433871
# UNIX ID: meinders
# Lecture: A1
# Lab: D01
# TA's Name: Chenyang Huang


lander: lander.c
	gcc -Wall -g -std=c99 -o lander lander.c -lm -lcurses

ball: ball.c
	gcc -Wall -g -std=c99 -o ball ball.c -lm -lncurses

timer: timer.c
	gcc -Wall -g -std=c99 -o timer timer.c -lm -lncurses

test_curses: test_curses.c
	gcc -Wall -g -std=c99 -o test_curses test_curses.c -lm -lncurses

clean:
	-rm -f -v *.o ball test_curses timer draw3 core
