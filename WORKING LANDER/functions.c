/* Name: Mandy Meindersma
 * One Card Number: 1433871
 * UNIX ID: meinders
 * Lecture: A1
 * Lab: D01
 * TA's Name: Chenyang Huang*/



#include "lander.h"



void drawThrusters(){

  //blocks signal
  sigset_t block_mask;
  sigset_t old_mask;
  sigemptyset( &block_mask );
  sigaddset( &block_mask, SIGALRM );
  if( sigprocmask( SIG_BLOCK, &block_mask, &old_mask ) < 0 ) {
    exit( EXIT_FAILURE );
  }
  int i;
for (i=0;i<=3;i++){
	if (improvements==1){
		fprintf(sketch, "setColor 238 0 0\n");
		fprintf(sketch, "drawSegment %li %li %li %li\n", lround(ship_array[13][0]), lround(ship_array[13][1]), lround(ship_array[14][0]), lround(ship_array[14][1]));
		fprintf(sketch, "drawSegment %li %li %li %li\n", lround(ship_array[13][0]), lround(ship_array[13][1]), lround(ship_array[15][0]), lround(ship_array[15][1]));
		fprintf(sketch, "drawSegment %li %li %li %li\n", lround(ship_array[13][0]), lround(ship_array[13][1]), lround(ship_array[16][0]), lround(ship_array[16][1]));
		fprintf(sketch, "setColor 238 154 0\n");
		fprintf(sketch, "drawSegment %li %li %li %li\n", lround(ship_array[13][0]), lround(ship_array[13][1]), lround(ship_array[17][0]), lround(ship_array[17][1]));
		fprintf(sketch, "drawSegment %li %li %li %li\n", lround(ship_array[13][0]), lround(ship_array[13][1]), lround(ship_array[18][0]), lround(ship_array[18][1]));
		fprintf(sketch, "drawSegment %li %li %li %li\n", lround(ship_array[19][0]), lround(ship_array[19][1]), lround(ship_array[20][0]), lround(ship_array[20][1]));
		fprintf(sketch, "drawSegment %li %li %li %li\n", lround(ship_array[21][0]), lround(ship_array[21][1]), lround(ship_array[22][0]), lround(ship_array[22][1]));
		fprintf(sketch, "setColor 0 0 0\n");
		fflush(sketch);
	}/*end if */
	else{
		fprintf(sketch, "drawSegment %li %li %li %li\n", lround(ship_array_normal[2][0]), lround(ship_array_normal[2][1]), 
																										 lround(ship_array_normal[4][0]), lround(ship_array_normal[4][1]));
		fprintf(sketch, "drawSegment %li %li %li %li\n", lround(ship_array_normal[4][0]), lround(ship_array_normal[4][1]), 
																										 lround(ship_array_normal[3][0]), lround(ship_array_normal[3][1]));
		fflush(sketch);
	}/*end else*/
}
  // unblock signal
  if( sigprocmask( SIG_SETMASK, &old_mask, NULL ) < 0 ) {
    exit( EXIT_FAILURE );
  }
}/*end drawthrusters*/


void update (){

	fprintf(sketch,"clearScreen\n");

	double change_in_y;
	double change_in_x;
	int f=0;
	change_in_y=(velocity_y*time)+(time*time*yA*0.5);
	change_in_x=(velocity_x*time)+(time*time*xA*0.5);
	velocity_y=velocity_y+(yA*time);
	velocity_x=velocity_x+(xA*time);

	if (improvements==1){
		for (f=0;f<23;f++){
			ship_array[f][0]=ship_array[f][0]+change_in_x;
			ship_array[f][1]=ship_array[f][1]+change_in_y;
		}/*end if */
	}/*end if */
	else{
		for (f=0;f<5;f++){
			ship_array_normal[f][0]=ship_array_normal[f][0]+change_in_x;
			ship_array_normal[f][1]=ship_array_normal[f][1]+change_in_y;
		}/*end if */
	}/*end else for the non impoved part*/
	drawShip();
	drawLandscape();
		if (spacebar==1){
			yA = gravity + (thrust * sin(angle_of_ship));
			drawThrusters();
	}/*end if*/
	spacebar=0;
}/* end update funcion*/

void handle_timeout(int signal){


  //blocks signal
  sigset_t block_mask;
  sigset_t old_mask;
  sigemptyset( &block_mask );
  sigaddset( &block_mask, SIGALRM );
  if( sigprocmask( SIG_BLOCK, &block_mask, &old_mask ) < 0 ) {
    exit( EXIT_FAILURE );}
  if( signal == SIGALRM ) {


  int a;

  a=(angle_of_ship*180)/M_PI;

  int v = velocity_y;


    update();
    yA=gravity;
    xA=0;




  int they_intersect;
  if (improvements==1){



  int m;
  for (m=0;m<number_of_landscape_points-1;m++){
  
      they_intersect=lineSegmentIntersection(array_of_landscape[m][0],array_of_landscape[m][1],array_of_landscape[m+1][0],array_of_landscape[m+1][1], 
                                             ship_array[1][0],ship_array[1][1],ship_array[2][0],ship_array[2][1]);
      if ((they_intersect==1)    && (a==90)   ){
        won=1;
        done=1;
        stop(1);}
        else if (they_intersect==1){
        won=0;
        done=1;
        stop(0);
      }
      they_intersect=lineSegmentIntersection(array_of_landscape[m][0],array_of_landscape[m][1],array_of_landscape[m+1][0],array_of_landscape[m+1][1], 
                                             ship_array[2][0],ship_array[2][1],ship_array[3][0],ship_array[3][1]);
      if ( (they_intersect==1)     && (a==90)   && (v<max_y_velocity) && (array_of_landscape[m][1]==array_of_landscape[m+1][1]) ){
        won=1;
      done=1;
        stop(1);}
        else if (they_intersect==1){
        won=0;
        done=1;
        stop(0);
      }
      they_intersect=lineSegmentIntersection(array_of_landscape[m][0],array_of_landscape[m][1],array_of_landscape[m+1][0],array_of_landscape[m+1][1], 
                                             ship_array[3][0],ship_array[3][1],ship_array[0][0],ship_array[0][1]);
      if ((they_intersect==1)      && (a==90)  && (v<max_y_velocity) && (array_of_landscape[m][1]==array_of_landscape[m+1][1])  ){
        won=1;
      done=1;
        stop(1);}
        else if (they_intersect==1){
        won=0;
        done=1;
        stop(0);
      }
      they_intersect=lineSegmentIntersection(array_of_landscape[m][0],array_of_landscape[m][1],array_of_landscape[m+1][0],array_of_landscape[m+1][1], 
                                             ship_array[0][0],ship_array[0][1],ship_array[4][0],ship_array[4][1]);
      if ((they_intersect==1)     && (a==90)  && (v<max_y_velocity) && (array_of_landscape[m][1]==array_of_landscape[m+1][1])  ){
        won=1;
      done=1;
        stop(1);}
        else if (they_intersect==1){
        won=0;
        done=1;
        stop(0);
      }
      they_intersect=lineSegmentIntersection(array_of_landscape[m][0],array_of_landscape[m][1],array_of_landscape[m+1][0],array_of_landscape[m+1][1], 
                                             ship_array[4][0],ship_array[4][1],ship_array[1][0],ship_array[1][1]);
      if ((they_intersect==1)     && (a==90)  && (v<max_y_velocity) && (array_of_landscape[m][1]==array_of_landscape[m+1][1]) ){
        won=1;
      done=1;
        stop(1);}
      else if (they_intersect==1){
        won=0;
        done=1;
        stop(0);
      }

  }/*end m for loop*/
}/*end improvements*/
  else{
  int m;

  for (m=0;m<number_of_landscape_points-1;m++){

    
      they_intersect=lineSegmentIntersection(array_of_landscape[m][0],array_of_landscape[m][1],array_of_landscape[m+1][0],array_of_landscape[m+1][1], 
                                              ship_array_normal[0][0],ship_array_normal[0][1],ship_array_normal[1][0],ship_array_normal[1][1]);
      if ((they_intersect==1)     && (a==90)  && (v<max_y_velocity) && (array_of_landscape[m][1]==array_of_landscape[m+1][1]) ){
        won=1;
        done=1;
        stop(1);}
        else if (they_intersect==1){
        won=0;
        done=1;
        stop(0);
      }
      they_intersect=lineSegmentIntersection(array_of_landscape[m][0],array_of_landscape[m][1],array_of_landscape[m+1][0],array_of_landscape[m+1][1], 
                                             ship_array_normal[1][0],ship_array_normal[1][1],ship_array_normal[2][0],ship_array_normal[2][1]);
      if ((they_intersect==1)      && (a==90) && (v<max_y_velocity) && (array_of_landscape[m][1]==array_of_landscape[m+1][1]) ){
        won=1;
        done=1;
        stop(1);}
        else if (they_intersect==1){
        won=0;
        done=1;
        stop(0);
      }
      they_intersect=lineSegmentIntersection(array_of_landscape[m][0],array_of_landscape[m][1],array_of_landscape[m+1][0],array_of_landscape[m+1][1], 
                                             ship_array_normal[2][0],ship_array_normal[2][1],ship_array_normal[3][0],ship_array_normal[3][1]);
      if ((they_intersect==1)     && (a==90) && (v<max_y_velocity) && (array_of_landscape[m][1]==array_of_landscape[m+1][1]) ){
        won=1;
        done=1;
        stop(1);}
        else if (they_intersect==1){
        won=0;
        done=1;
        stop(0);
      }
      they_intersect=lineSegmentIntersection(array_of_landscape[m][0],array_of_landscape[m][1],array_of_landscape[m+1][0],array_of_landscape[m+1][1], 
                                             ship_array_normal[3][0],ship_array_normal[3][1],ship_array_normal[0][0],ship_array_normal[0][1]);
      if ((they_intersect==1)     && (a==90)  && (v<max_y_velocity) && (array_of_landscape[m][1]==array_of_landscape[m+1][1]) ){
        won=1;
        done=1;
        stop(1);}
      else if (they_intersect==1){
        won=0;
        done=1;
        stop(0);

      }
  }/*end m for loop*/
}/*end esle*/

}


  // unblock signal
  if( sigprocmask( SIG_SETMASK, &old_mask, NULL ) < 0 ) {
    exit( EXIT_FAILURE );
  }/*end if*/
}/*end handle timeout*/





//  public domain function by Darel Rex Finley, 2006
//  Determines the intersection point of the line segment defined by points A and B
//  with the line segment defined by points C and D.
//  Returns YES if the intersection point was found
//  Returns NO if there is no determinable intersection point
int lineSegmentIntersection(double Ax, double Ay, double Bx, double By,
														 double Cx, double Cy, double Dx, double Dy) {

  double  distAB, theCos, theSin, newX, ABpos ;
  //  Fail if either line segment is zero-length.
  if ((Ax==Bx && Ay==By) || (Cx==Dx && Cy==Dy)) return NO;
  //  Fail if the segments share an end-point.
  if ((Ax==Cx && Ay==Cy) || (Bx==Cx && By==Cy) ||  (Ax==Dx && Ay==Dy) || (Bx==Dx && By==Dy)) {return NO; }
  //  (1) Translate the system so that point A is on the origin.
  Bx-=Ax; By-=Ay;
  Cx-=Ax; Cy-=Ay;
  Dx-=Ax; Dy-=Ay;
  //  Discover the length of segment A-B.
  distAB=sqrt(Bx*Bx+By*By);
  //  (2) Rotate the system so that point B is on the positive X axis.
  theCos=Bx/distAB;
  theSin=By/distAB;
  newX=Cx*theCos+Cy*theSin;
  Cy  =Cy*theCos-Cx*theSin; Cx=newX;
  newX=Dx*theCos+Dy*theSin;
  Dy  =Dy*theCos-Dx*theSin; Dx=newX;
  //  Fail if segment C-D doesn't cross line A-B.
  if ((Cy<0. && Dy<0.) || (Cy>=0. && Dy>=0.)) return NO;
  //  (3) Discover the position of the intersection point along line A-B.
  ABpos=Dx+(Cx-Dx)*Dy/(Dy-Cy);
  //  Fail if segment C-D crosses line A-B outside of segment A-B.
  if (ABpos<0. || ABpos>distAB) return NO;
  //  Success.
  return YES;
}
/*end lineSegmentInersection*/




void stop(int what_message){

  shutdown_ncurses();

  struct itimerval timer;
  // turn the timer off by setting the values to 0/0
  timer.it_interval.tv_sec = 0;
  timer.it_interval.tv_usec = 0;
  timer.it_value.tv_sec = 0;
  timer.it_value.tv_usec = 0;
  if( setitimer( ITIMER_REAL, &timer, NULL ) < 0 ) {
    exit( EXIT_FAILURE );
  }
  move(12,10);
  if (what_message==1){
    printw(  "landed!!! :) :D");
    
  }
  else{
    printw( "Crashed!!! :( noooooo"  );
  }


}






