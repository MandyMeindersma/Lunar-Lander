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
color=color+10;
if (done==0){
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



}/*end done if*/

  else if((done==1) && (won==1) && (improvements==1)){
  
  draw_landed(color);
}


else if((done==1) && (won==0) && (improvements==1)){
  draw_crashed();
}



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
  	what_time_is_it++;
  	if (what_time_is_it==when_to_change_star && improvements==1){make_star_array();drawstar=1;}
    int a;
    a=(angle_of_ship*180)/M_PI;
    //if (fuel_level<0){fuel_level=0;}
    int v = velocity_y;
    update();
    yA=gravity;
    xA=0;
    if (improvements==1 && (drawstar==1) && (done==0)){draw_token();}
    int they_intersect;
    if (improvements==1){
      int m;
      for (m=0;m<number_of_landscape_points-1;m++){
        they_intersect=lineSegmentIntersection(array_of_landscape[m][0],array_of_landscape[m][1],array_of_landscape[m+1][0],array_of_landscape[m+1][1], 
                                             ship_array[1][0],ship_array[1][1],ship_array[2][0],ship_array[2][1]);
        if ((they_intersect==1) && (a==90)  && (v<max_y_velocity) && (array_of_landscape[m][1]==array_of_landscape[m+1][1]) ){
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
        if ( (they_intersect==1) && (a==90) && (v<max_y_velocity) && (array_of_landscape[m][1]==array_of_landscape[m+1][1]) ){
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
        if ((they_intersect==1) && (a==90) && (v<max_y_velocity) && (array_of_landscape[m][1]==array_of_landscape[m+1][1])  ){
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
        if ((they_intersect==1) && (a==90) && (v<max_y_velocity) && (array_of_landscape[m][1]==array_of_landscape[m+1][1])  ){
          won=1;
          done=1;
          stop(1);
        }
        else if (they_intersect==1){
          won=0;
          done=1;
          stop(0);
        }
        they_intersect=lineSegmentIntersection(array_of_landscape[m][0],array_of_landscape[m][1],array_of_landscape[m+1][0],array_of_landscape[m+1][1], 
                                             ship_array[4][0],ship_array[4][1],ship_array[1][0],ship_array[1][1]);
        if ((they_intersect==1) && (a==90) && (v<max_y_velocity) && (array_of_landscape[m][1]==array_of_landscape[m+1][1]) ){
          won=1;
          done=1;
          stop(1);
        }
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
        if ((they_intersect==1) && (a==90) && (v<max_y_velocity) && (array_of_landscape[m][1]==array_of_landscape[m+1][1]) ){
          won=1;
          done=1;
          stop(1);
        }
        else if (they_intersect==1){
          won=0;
          done=1;
          stop(0);
        }
        they_intersect=lineSegmentIntersection(array_of_landscape[m][0],array_of_landscape[m][1],array_of_landscape[m+1][0],array_of_landscape[m+1][1], 
                                               ship_array_normal[1][0],ship_array_normal[1][1],ship_array_normal[2][0],ship_array_normal[2][1]);
        if ((they_intersect==1) && (a==90) && (v<max_y_velocity) && (array_of_landscape[m][1]==array_of_landscape[m+1][1]) ){
          won=1;
          done=1;
          stop(1);
        }
        else if (they_intersect==1){
          won=0;
          done=1;
          stop(0);
        }
        they_intersect=lineSegmentIntersection(array_of_landscape[m][0],array_of_landscape[m][1],array_of_landscape[m+1][0],array_of_landscape[m+1][1], 
                                               ship_array_normal[2][0],ship_array_normal[2][1],ship_array_normal[3][0],ship_array_normal[3][1]);
        if ((they_intersect==1) && (a==90) && (v<max_y_velocity) && (array_of_landscape[m][1]==array_of_landscape[m+1][1]) ){
          won=1;
          done=1;
          stop(1);
        }
        else if (they_intersect==1){
          won=0;
          done=1;
          stop(0);
        }
        they_intersect=lineSegmentIntersection(array_of_landscape[m][0],array_of_landscape[m][1],array_of_landscape[m+1][0],array_of_landscape[m+1][1], 
                                               ship_array_normal[3][0],ship_array_normal[3][1],ship_array_normal[0][0],ship_array_normal[0][1]);
        if ((they_intersect==1) && (a==90)  && (v<max_y_velocity) && (array_of_landscape[m][1]==array_of_landscape[m+1][1]) ){
          won=1;
          done=1;
          stop(1);
        }
        else if (they_intersect==1){
          won=0;
          done=1;
          stop(0);
        }
      }/*end m for loop*/
    }/*end esle*/
    check_outside();
    if (drawstar==1){check_hit_token();}
    if (done==0){fuel_bar();}
  }/*end signal thing*/


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

  move(12,10);
  if (what_message==1){
    printw("Landed!!! :) :D");
    //draw_landed();
  }
  else{
    printw( "Crashed!!! :( noooooo"  );
  }

  shutdown_ncurses();
  /*struct itimerval timer;
  // turn the timer off by setting the values to 0/0
  timer.it_interval.tv_sec = 0;
  timer.it_interval.tv_usec = 0;
  timer.it_value.tv_sec = 0;
  timer.it_value.tv_usec = 0;
  if( setitimer( ITIMER_REAL, &timer, NULL ) < 0 ) {
    exit( EXIT_FAILURE );
  }*/

}/*end stop*/

void check_outside(){
  int lowest_x, highest_x, lowest_y;
  lowest_x=1000;
  lowest_y=1000;
  highest_x=-1000;
  if (improvements==1){
    int g;
    for (g=0;g<=5;g++){
      if (ship_array[g][0]<lowest_x){
        lowest_x=lround(ship_array[g][0]);
      }
      if (ship_array[g][0]>highest_x){
        highest_x=lround(ship_array[g][0]);
      }
      if (ship_array[g][1]<lowest_y){
        lowest_y=lround(ship_array[g][1]);
      }
    }/*end for*/
  }/*end if improvements*/
  else{
    int g;
    for (g=0;g<=4;g++){
      if (ship_array_normal[g][0]<lowest_x){
        lowest_x=lround(ship_array_normal[g][0]);
      }
      if (ship_array_normal[g][0]>highest_x){
        highest_x=lround(ship_array_normal[g][0]);
      }
      if (ship_array_normal[g][1]<lowest_y){
        lowest_y=lround(ship_array_normal[g][1]);
      }
    }/*end for*/
  }/*end else improvements*/  
  if ((lowest_y<=0)  )  {
    velocity_y=10;
    velocity_x=0;
  }
  if (lowest_x<=0) {
    velocity_y=0;
    velocity_x=10;
  }
  if (highest_x>=640){
    velocity_y=0;
    velocity_x=-10;
  }
}/*end check outside*/


void draw_landed(){
  if (improvements==1){
 
      fprintf(sketch, "setColor %d %d %d\n",color%255,(color+60)%255, (color+160)%255);
      //underline
      fprintf(sketch, "drawSegment 85 215 475 215\n");
      //L
      fprintf(sketch, "drawSegment 100 100 100 200\n");
      fprintf(sketch, "drawSegment 100 200 150 200\n");
      //A
      fprintf(sketch, "drawSegment 175 200 200 100\n");
      fprintf(sketch, "drawSegment 200 100 225 200\n");
      fprintf(sketch, "drawSegment 187 150 213 150\n");
      //N
      fprintf(sketch, "drawSegment 250 200 250 100\n");
      fprintf(sketch, "drawSegment 250 100 275 200\n");
      fprintf(sketch, "drawSegment 275 200 275 100\n");
      //D
      fprintf(sketch, "drawSegment 300 200 300 100\n");
      fprintf(sketch, "drawSegment 300 100 325 100\n");
      fprintf(sketch, "drawSegment 300 200 325 200\n");
      fprintf(sketch, "drawSegment 340 180 340 120\n");
      fprintf(sketch, "drawSegment 340 180 325 200\n");
      fprintf(sketch, "drawSegment 340 120 325 100\n");
      //E
      fprintf(sketch, "drawSegment 365 100 365 200\n");
      fprintf(sketch, "drawSegment 365 100 400 100\n");
      fprintf(sketch, "drawSegment 365 150 385 150\n");
      fprintf(sketch, "drawSegment 365 200 400 200\n");
      //D
      fprintf(sketch, "drawSegment 425 200 425 100\n");
      fprintf(sketch, "drawSegment 425 100 450 100\n");
      fprintf(sketch, "drawSegment 425 200 450 200\n");
      fprintf(sketch, "drawSegment 465 180 465 120\n");
      fprintf(sketch, "drawSegment 465 180 450 200\n");
      fprintf(sketch, "drawSegment 465 120 450 100\n");
      //smile
      fprintf(sketch, "drawSegment 485 150 485 180\n");
      fprintf(sketch, "drawSegment 585 150 585 180\n");
      fprintf(sketch, "drawSegment 505 200 565 200\n");
      fprintf(sketch, "drawSegment 485 180 505 200\n");
      fprintf(sketch, "drawSegment 565 200 585 180\n");
      //cheeks
      fprintf(sketch, "drawSegment 480 150 490 150\n");
      fprintf(sketch, "drawSegment 580 150 590 150\n");
      fprintf(sketch, "drawSegment 480 150 475 145\n");
      fprintf(sketch, "drawSegment 490 150 495 145\n");
      fprintf(sketch, "drawSegment 580 150 575 145\n");
      fprintf(sketch, "drawSegment 590 150 595 145\n");
      //eyes
      fprintf(sketch, "drawSegment 510 100 520 100\n");
      fprintf(sketch, "drawSegment 560 100 550 100\n");
      fprintf(sketch, "drawSegment 560 100 560 150\n");
      fprintf(sketch, "drawSegment 550 100 550 150\n");
      fprintf(sketch, "drawSegment 510 100 510 150\n");
      fprintf(sketch, "drawSegment 520 100 520 150\n");
      fprintf(sketch, "drawSegment 510 150 520 150\n");
      fprintf(sketch, "drawSegment 560 150 550 150\n");
      //tongue
      fprintf(sketch, "drawSegment 550 200 550 210\n");
      fprintf(sketch, "drawSegment 550 210 565 235\n");
      fprintf(sketch, "drawSegment 575 190 582 197\n");
      fprintf(sketch, "drawSegment 582 197 597 222\n");
      fprintf(sketch, "drawSegment 580 245 597 237\n");
      fprintf(sketch, "drawSegment 580 245 565 235\n");
      fprintf(sketch, "drawSegment 597 237 597 222\n");
      fprintf(sketch, "drawSegment 565 200 582 230\n");

      fflush(sketch);
  
  }/*end if*/
}






void draw_crashed(){

  double the_middle_x;
  double the_middle_y;
  the_middle_x=get_x_midpoint();
  the_middle_y=get_y_midpoint();
  int f,g,h,u;
  int x1=0,y1=0,x2=0,y2=0;



  int l;
  for (l=0;l<=100;l++){
    f=rand();
    g=rand();
    h=rand();
    u=rand();
    f=f%99;
    g=g%99;
    h=h%99;
    u=u%97;
    /*x1=(f)%20;
    y1=(f)%18;
    x2=(f)%19;
    y2=(f)%17;*/
    f=f-50;
    g=g-50;
    h=h-50;
    u=u-50;
    x1=(f+the_middle_x);
    y1=(g+the_middle_y);
    x2=(x1+u);
    y2=(y1+h);
    fprintf(sketch, "setColor %d %d %d\n",color%255,(color+60)%255, (color+160)%255);
    fprintf(sketch, "drawSegment %d %d %d %d\n", x1,y1,x2,y2 );
    //fprintf(sketch, "drawSegment %d %d %d %d\n", x1,y2,x2,y1 );
  }


}
