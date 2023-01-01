Name: Mandy Meindersma
One Card Number: 1433871
UNIX ID: meinders
Lecture: A1
Lab: D01
TA’s Name: Chenyang Huang


This is my assignment3! A working lunar lander!
I made one version which works exactly like the lunar lander on eclass and I also made my own improved version.
My improvements are:
1-A pretty ship with cool colors and fun thrusters
2-A colorful explosion when you crash
3-A color changing landing message
4-A fuel bar that is green if you have a lot of fuel and will change to yellow and then red if you are getting too low
5-If you find yourself with not enough fuel try to make it to the yellow star! You will be rewarded with a ton of fuel!

Couple other facts about my program:
You must have a velocity less than 20 to land, along with being upright on a flat surface.
When you bump into the sides you are gently pushed in the opposite direction.
The star is placed 2 seconds after you start the program to make it a little harder. 
The star is randomly placed each time you run the game based on your velocity, angle of ship, thrust and gravity.
I do not use getop() so I am expecting perfect input.



To make this program I looked at man pages, class slides and asked  
Sarah Hoven questions about the timer, angle of ship to win and how to get random numbers to generate lines.
Bennett Hreherchuk told me the order of my program (print landed before shutting program down).
I used code from timer.c and ncurses.c from eclass.
I used code from the intersection code from eclass from a guy named Darel Rex Finley.


Compile by typing make

Run default version by typing ./lander -g 9.8 -t 20 -f landscape.txt
**note this is just an example! 
**-g is for gravity. Please put a number in after
**-t is for thrust. Please put a number in after
**-f is for an input file. Any input file will work


Run IMPROVEMENT VERSION by typing ./lander -g 9.8 -t 20 -f landscape.txt -i
**note this is just an example! 
**-g is for gravity. Please put a number in after
**-t is for thrust. Please put a number in after
**-f is for an input file. Any input file will work
**-i is for all the impovements I have made
