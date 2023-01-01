/* Name: Mandy Meindersma
 * One Card Number: 1433871
 * UNIX ID: meinders
 * Lecture: A1
 * Lab: D01
 * TA's Name: Chenyang Huang*/

/*I got this code from eclass. I took parts from eclass and then added my own code to this .c file*/


#include "lander.h"

int test_curses(){
  yA=gravity;
  xA=0;
  angle_of_ship=M_PI/2;
  spacebar=0;
  struct sigaction handler;

  // set up signal handler (man 2 sigaction)
  /* *********************************************************** */

  // handle_timeout is function to call when signal is sent
  handler.sa_handler = handle_timeout;
  // empties sa_mask, meaning no signals will be blocked while our
  // signal handler (handle_timeout) is executing
  sigemptyset( &handler.sa_mask );
  // various options. we don't need any for this program
  handler.sa_flags = 0;

  // use signal handler defined in handler to handle SIGALRM signals
  if( sigaction( SIGALRM, &handler, NULL ) < 0 ) {
    exit( EXIT_FAILURE );
  }

  int running, c;

  init_ncurses();

  mvprintw( 5, 10, "Press any key to start." );
  refresh(); // printed output doesn't appear until we refresh
  c = getch();

  drawLandscape(array_of_landscape, number_of_landscape_points);
  drawShip();

  struct itimerval timer;

  // value for time until first SIGALRM
  timer.it_value.tv_sec = 0;  // 0 in the example lander program
  timer.it_value.tv_usec = 50000; // 50000 in the example lander program
  // interval between subsequent alarms
  timer.it_interval.tv_sec = 0;  // 0 in the example lander program
  timer.it_interval.tv_usec = 50000; // 50000 in the example lander program

  // will execute repeatedly, sending SIGALRM every timer.it_interval
  // seconds/microseconds, with an inital delay of timer.it_value.
  if( setitimer( ITIMER_REAL, &timer, NULL ) < 0 ) {
    exit( EXIT_FAILURE );
  }

  nodelay( stdscr, TRUE ); // have getch() return ERR if input isn't ready

  erase();
  mvprintw( 5, 0, "Left arrow key rotates counter-clockwise\nRight arrow key rotates clockwise\nSpace bar for thrust\n'q' to quit." );
  refresh();

  running = 1;
  do {
    c = getch();
    if( c == ERR ) { continue; } // keep looping until we get input

    // in asn3, won't need to do any printing to screen.
    // instead, will rotate figure on left or right arrow keys, and
    // initiate thrust when space bar is pressed.
    erase();
    mvprintw( 5, 0, "Left arrow key rotates counter-clockwise\nRight arrow key rotates clockwise\nSpace bar for thrust\n'q' to quit." );
    move( 10, 10 );
    switch( c ) {

    case KEY_LEFT:
      printw( "left key pressed" );
      //eraseShip();
      rotate("left");
      //drawShip();
      break;

    case KEY_RIGHT:
      printw( "right key pressed" );
      //eraseShip();
      rotate("right");
      //drawShip();
      break;

    case ' ':
      printw( "space bar pressed" );
      spacebar=1;
      thrust_the_ship();
      drawThrusters();
      break;

    case 'q':
      running = 0;
      break;

    case 'Q':
      running = 0;
      break;

    default:
      // do nothing
      break;
    }
    refresh();
  } while( running );

  // must do this or else the terminal will be unusable
  shutdown_ncurses();
  return EXIT_SUCCESS;
}/*end test_curses*/

void init_ncurses(){
  int r;
  // start up the ncurses environment
  initscr(); // nothing to check, initscr exits on error
  // don't wait for enter for keyboard input
  r = cbreak(); assert( r != ERR );
  // don't echo keypresses to screen
  r = noecho(); assert( r != ERR );
  r = nonl(); assert( r != ERR );
  // turn cursor off
  r = curs_set( 0 ); assert( r != ERR );
  // don't worry about cursor position
  r = leaveok( stdscr, TRUE ); assert( r != ERR );
  // slower handling of ^C but saner output
  r = intrflush( stdscr, FALSE ); assert( r != ERR );
  // translate movement espace codes into single keys
  r = keypad( stdscr, TRUE ); assert( r != ERR );
}/*end init_ncurses*/

void shutdown_ncurses(){
  endwin();
}/*end shutdown_ncurses*/
