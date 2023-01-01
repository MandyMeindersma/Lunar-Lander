/* Name: Mandy Meindersma
 * One Card Number: 1433871
 * UNIX ID: meinders
 * Lecture: A1
 * Lab: D01
 * TA's Name: Chenyang Huang
 */


#ifndef LANDER_H
#define LANDER_H

#define _XOPEN_SOURCE 700

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <ncurses.h>
#include <unistd.h>
#include <signal.h> // for signal handling
#include <sys/time.h> // for the timer
#include <time.h>




/*----------------------------------------------------------*/
/*macros found from eclass*/
#define size_of_instruction 200
#define size_of_landscape_point 23
#define time 0.05
#define YES 1
#define NO 0
#define max_y_velocity 30
#define when_to_change_star 40
#define space_bar_dec 1
#define fuel_level_inc 100



/*-------------------------------------------------------------*/
/*global variables*/
  double gravity;
  double thrust;
  double velocity_y;
  double velocity_x;
  double ship_array[23][2];
  double ship_array_normal[5][2];
  FILE* sketch;
  //if improvements is equal to zero then do zero improvements
  int improvements;
  long array_of_landscape[size_of_landscape_point][2];
	int number_of_landscape_points;
  int spacebar;
  double angle_of_ship;
  double xA;
  double yA;
  int won;
  int done;
  int running;
  int color;
  int tokenx;
  int tokeny;
  int token_array[20][2];
  int what_time_is_it;
  int drawstar;
  int fuel_level;



/*-----------------------------------------------------------------*/
/* Function declarations for draw1b.c functions. */
/* See comments in program for more information. */

void parseFile(FILE *landscape_file);

void drawShip();

void drawLandscape();

double get_x_midpoint();

double get_y_midpoint();

void rotate( char *rotate_direction);

void eraseShip();

void drawThrusters();

void eraseThrusters();

void init_ncurses();

void shutdown_ncurses();

int test_curses();

void update ();

int timer();

void handle_timeout( int signal );

int lineSegmentIntersection(double Ax, double Ay, double Bx, double By, double Cx, double Cy, double Dx, double Dy);

void stop(int what_message);

void check_outside();

void draw_landed();

void draw_crashed();

void draw_token();

void make_star_array();

int check_hit_token();

void fuel_bar();


#endif