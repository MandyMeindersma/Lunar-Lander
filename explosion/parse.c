/* Name: Mandy Meindersma
 * One Card Number: 1433871
 * UNIX ID: meinders
 * Lecture: A1
 * Lab: D01
 * TA's Name: Chenyang Huang*/


#include "lander.h"


void parseFile(FILE* landscape_file){

	drawstar=0;

	//normal ship
	ship_array_normal[0][0]=280;
	ship_array_normal[0][1]=10;
	ship_array_normal[1][0]=300;
	ship_array_normal[1][1]=10;
	ship_array_normal[2][0]=310;
	ship_array_normal[2][1]=40;
	ship_array_normal[3][0]=270;
	ship_array_normal[3][1]=40;
	//thruster
	ship_array_normal[4][0]=290;
	ship_array_normal[4][1]=50;


	//improved ship
	ship_array[0][0]=290;
	ship_array[0][1]=15;
	ship_array[1][0]=300;
	ship_array[1][1]=55;
	ship_array[2][0]=280;
	ship_array[2][1]=55;
	ship_array[3][0]=270;
	ship_array[3][1]=45;
	ship_array[4][0]=310;
	ship_array[4][1]=45;
	//end of ship
	//start top band
	ship_array[5][0]=285;
	ship_array[5][1]=40;
	ship_array[6][0]=297;
	ship_array[6][1]=40;
	ship_array[7][0]=302;
	ship_array[7][1]=34;
	ship_array[8][0]=278;
	ship_array[8][1]=34;
	//start bottom band
	ship_array[9][0]=283;
	ship_array[9][1]=45;
	ship_array[10][0]=297;
	ship_array[10][1]=45;
	ship_array[11][0]=304;
	ship_array[11][1]=38;
	ship_array[12][0]=276;
	ship_array[12][1]=38;
	//start thrust
	ship_array[13][0]=290;
	ship_array[13][1]=57;
	//straight
	ship_array[14][0]=290;
	ship_array[14][1]=75;
	//right
	ship_array[15][0]=295;
	ship_array[15][1]=75;
	//left
	ship_array[16][0]=285;
	ship_array[16][1]=75;
	//more right
	ship_array[17][0]=300;
	ship_array[17][1]=70;
	//more left
	ship_array[18][0]=280;
	ship_array[18][1]=70;
	//start right
	ship_array[19][0]=295;
	ship_array[19][1]=57;
	ship_array[20][0]=305;
	ship_array[20][1]=70;
	//start left
	ship_array[21][0]=285;
	ship_array[21][1]=57;
	ship_array[22][0]=275;
	ship_array[22][1]=70;


	
	


	char line[size_of_instruction];
	long x_land,y_land;
	won=0;
	done=0;
	color=0;
	what_time_is_it=0;
	fuel_level=500;



	//getting landscape points
	while (fgets(line,size_of_instruction+1,landscape_file)){
		sscanf(line,"%li %li",&x_land,&y_land);
		array_of_landscape[number_of_landscape_points][0]=x_land;
		array_of_landscape[number_of_landscape_points][1]=y_land;
		number_of_landscape_points++;
	}/*end while*/


	//start game
	test_curses();
}/*end parseFile*/


void drawShip(){

	//block signal
  sigset_t block_mask;
  sigset_t old_mask;
  sigemptyset( &block_mask );
  sigaddset( &block_mask, SIGALRM );
  if( sigprocmask( SIG_BLOCK, &block_mask, &old_mask ) < 0 ) {
    exit( EXIT_FAILURE );
  }


	if (improvements==1){
		fprintf(sketch, "drawSegment %li %li %li %li\n", lround(ship_array[0][0]), lround(ship_array[0][1]), lround(ship_array[1][0]), lround(ship_array[1][1]));
		fprintf(sketch, "drawSegment %li %li %li %li\n", lround(ship_array[1][0]), lround(ship_array[1][1]), lround(ship_array[2][0]), lround(ship_array[2][1]));
		fprintf(sketch, "drawSegment %li %li %li %li\n", lround(ship_array[2][0]), lround(ship_array[2][1]), lround(ship_array[0][0]), lround(ship_array[0][1]));
		fprintf(sketch, "drawSegment %li %li %li %li\n", lround(ship_array[0][0]), lround(ship_array[0][1]), lround(ship_array[3][0]), lround(ship_array[3][1]));
		fprintf(sketch, "drawSegment %li %li %li %li\n", lround(ship_array[3][0]), lround(ship_array[3][1]), lround(ship_array[2][0]), lround(ship_array[2][1]));
		fprintf(sketch, "drawSegment %li %li %li %li\n", lround(ship_array[1][0]), lround(ship_array[1][1]), lround(ship_array[4][0]), lround(ship_array[4][1]));
		fprintf(sketch, "drawSegment %li %li %li %li\n", lround(ship_array[4][0]), lround(ship_array[4][1]), lround(ship_array[0][0]), lround(ship_array[0][1]));
		fprintf(sketch, "setColor 0 191 255\n");
		fprintf(sketch, "drawSegment %li %li %li %li\n", lround(ship_array[5][0]), lround(ship_array[5][1]), lround(ship_array[6][0]), lround(ship_array[6][1]));
		fprintf(sketch, "drawSegment %li %li %li %li\n", lround(ship_array[6][0]), lround(ship_array[6][1]), lround(ship_array[7][0]), lround(ship_array[7][1]));
		fprintf(sketch, "drawSegment %li %li %li %li\n", lround(ship_array[5][0]), lround(ship_array[5][1]), lround(ship_array[8][0]), lround(ship_array[8][1]));
		fprintf(sketch, "setColor 255 0 255\n");
		fprintf(sketch, "drawSegment %li %li %li %li\n", lround(ship_array[9][0]), lround(ship_array[9][1]), lround(ship_array[10][0]), lround(ship_array[10][1]));
		fprintf(sketch, "drawSegment %li %li %li %li\n", lround(ship_array[10][0]), lround(ship_array[10][1]), lround(ship_array[11][0]), lround(ship_array[11][1]));
		fprintf(sketch, "drawSegment %li %li %li %li\n", lround(ship_array[9][0]), lround(ship_array[9][1]), lround(ship_array[12][0]), lround(ship_array[12][1]));
		fprintf(sketch, "setColor 0 0 0\n");
		fflush(sketch);
	}/*end if for improvements*/
	else{
		fprintf(sketch, "drawSegment %li %li %li %li\n", lround(ship_array_normal[0][0]), lround(ship_array_normal[0][1]), 
																										 lround(ship_array_normal[1][0]), lround(ship_array_normal[1][1]));		
		fprintf(sketch, "drawSegment %li %li %li %li\n", lround(ship_array_normal[1][0]), lround(ship_array_normal[1][1]), 
																										 lround(ship_array_normal[2][0]), lround(ship_array_normal[2][1]));		
		fprintf(sketch, "drawSegment %li %li %li %li\n", lround(ship_array_normal[2][0]), lround(ship_array_normal[2][1]), 
																										 lround(ship_array_normal[3][0]), lround(ship_array_normal[3][1]));		
		fprintf(sketch, "drawSegment %li %li %li %li\n", lround(ship_array_normal[3][0]), lround(ship_array_normal[3][1]), 
																										 lround(ship_array_normal[0][0]), lround(ship_array_normal[0][1]));
		fflush(sketch);
	}/*end else for improvements*/

  // unblock signal
  if( sigprocmask( SIG_SETMASK, &old_mask, NULL ) < 0 ) {
    exit( EXIT_FAILURE );
  }
}/*end draw ship*/



void drawLandscape(){
	int m;
	for (m=0;m<number_of_landscape_points-1;m++){
		fprintf(sketch, "drawSegment %li %li %li %li\n", array_of_landscape[m][0],array_of_landscape[m][1],array_of_landscape[m+1][0],array_of_landscape[m+1][1]);
	}/*end for*/
	fflush(sketch);
}/*end drawlandscape*/


double get_x_midpoint(){
	int middlex;
	int g;
	int lowest=1000;
	int highest=-1000;
	if (improvements==1){
		//finding lowest and highest point of ship for x
		for (g=0;g<13;g++){
			if (ship_array[g][0]<lowest){
				lowest=ship_array[g][0];
			}/*end if*/
			if (ship_array[g][0]>highest){
				highest=ship_array[g][0];
			}/*end if*/
		}/*end for*/
	}/*end if*/
	else{
		//finding lowest and highest point of ship for x
		for (g=0;g<4;g++){
			if (ship_array_normal[g][0]<lowest){
				lowest=ship_array_normal[g][0];
			}/*end if*/
			if (ship_array_normal[g][0]>highest){
				highest=ship_array_normal[g][0];
			}/*end if*/
		}/*end for*/
	}
	middlex=(lowest+highest)/2;
	return middlex;
}/*end get middle x*/

double get_y_midpoint(){
 	int middley;
 	int g;
	int lowest=1000;
	int highest=-1000;

	if (improvements==1){
		//finding lowest and highest point of ship for y
		for (g=0;g<13;g++){
			if (ship_array[g][1]<lowest){
				lowest=ship_array[g][1];
			}/*end if*/
			if (ship_array[g][1]>highest){
				highest=ship_array[g][1];
			}/*end if*/
		}/*end for*/
	}/*end if*/
	else{
		//finding lowest and highest point of ship for x
		for (g=0;g<4;g++){
			if (ship_array_normal[g][1]<lowest){
				lowest=ship_array_normal[g][1];
			}/*end if*/
			if (ship_array_normal[g][1]>highest){
				highest=ship_array_normal[g][1];
			}/*end if*/
		}/*end for*/
	}
	middley=(lowest+highest)/2;
	return middley;
}/*end get middle y*/


void rotate( char *rotate_direction){

	//blocking signals
  sigset_t block_mask;
  sigset_t old_mask;
  sigemptyset( &block_mask );
  sigaddset( &block_mask, SIGALRM );
  if( sigprocmask( SIG_BLOCK, &block_mask, &old_mask ) < 0 ) {
    exit( EXIT_FAILURE );
  }


	double the_middle_x;
	double the_middle_y;
	double angle=0;
  the_middle_x=get_x_midpoint();
	the_middle_y=get_y_midpoint();

  if (strncmp("left", rotate_direction, 4)==0){
  	angle = -10* M_PI /180.0;
  	angle_of_ship+=angle;
  }/*end if*/
  else{
  	angle = 10* M_PI /180.0;
  	angle_of_ship+=angle;
  }/*end else*/

  int h;
  double x=0;
  double y=0;
  double new_x=0;
  double new_y=0;

  if (improvements==1){
  	for (h=0;h<=22;h++){
  		x=ship_array[h][0];
  		y=ship_array[h][1];
  		x=x - the_middle_x;
  		y=y - the_middle_y;
  		new_x=(x*cos(angle)) - (y*sin(angle));
			new_y=(x*sin(angle)) + (y*cos(angle));
			new_x=new_x + the_middle_x;
  		new_y=new_y + the_middle_y;
			ship_array[h][0]=new_x;
			ship_array[h][1]=new_y;
  	}/*end for*/
	}
	else{
  	for (h=0;h<=4;h++){
  		x=ship_array_normal[h][0];
  		y=ship_array_normal[h][1];
  		x=x - the_middle_x;
  		y=y - the_middle_y;
  		new_x=(x*cos(angle)) - (y*sin(angle));
			new_y=(x*sin(angle)) + (y*cos(angle));
			new_x=new_x + the_middle_x;
  		new_y=new_y + the_middle_y;
			ship_array_normal[h][0]=new_x;
			ship_array_normal[h][1]=new_y;
		}/*end for*/
	}/*end else*/

  // unblock signal
  if( sigprocmask( SIG_SETMASK, &old_mask, NULL ) < 0 ) {
    exit( EXIT_FAILURE );
  }
}/*end rotate*/





void draw_token(){

	
	fprintf(sketch, "setColor 255 140 0\n");
	fprintf(sketch, "drawSegment %d %d %d %d\n",token_array[0][0],token_array[0][1],token_array[1][0],token_array[1][1]);
	fprintf(sketch, "drawSegment %d %d %d %d\n",token_array[2][0],token_array[2][1],token_array[3][0],token_array[3][1]);
	fprintf(sketch, "drawSegment %d %d %d %d\n",token_array[4][0],token_array[4][1],token_array[5][0],token_array[5][1]);
	fprintf(sketch, "drawSegment %d %d %d %d\n",token_array[6][0],token_array[6][1],token_array[7][0],token_array[7][1]);
	fprintf(sketch, "drawSegment %d %d %d %d\n",token_array[8][0],token_array[8][1],token_array[9][0],token_array[9][1]);
	fprintf(sketch, "drawSegment %d %d %d %d\n",token_array[10][0],token_array[10][1],token_array[11][0],token_array[11][1]);
	fprintf(sketch, "drawSegment %d %d %d %d\n",token_array[12][0],token_array[12][1],token_array[13][0],token_array[13][1]);
	fprintf(sketch, "drawSegment %d %d %d %d\n",token_array[14][0],token_array[14][1],token_array[15][0],token_array[15][1]);
	fprintf(sketch, "drawSegment %d %d %d %d\n",token_array[16][0],token_array[16][1],token_array[17][0],token_array[17][1]);
	fprintf(sketch, "drawSegment %d %d %d %d\n",token_array[18][0],token_array[18][1],token_array[19][0],token_array[19][1]);

	fprintf(sketch, "setColor 0 0 0\n");

fflush(sketch);



}



void make_star_array(){

	tokenx=abs(angle_of_ship*5*ship_array[5][1]);
	tokeny=abs(angle_of_ship*7*yA*ship_array[6][1]);
	tokenx=tokenx%500;
	tokeny=tokeny%200;


	//storing star in token
	token_array[0][0]=113+tokenx;
	token_array[0][1]=100+tokeny-50;
	token_array[1][0]=118+tokenx;
	token_array[1][1]=110+tokeny-50;
	token_array[2][0]=113+tokenx;
	token_array[2][1]=100+tokeny-50;
	token_array[3][0]=110+tokenx;
	token_array[3][1]=110+tokeny-50;
	token_array[4][0]=110+tokenx;
	token_array[4][1]=110+tokeny-50;
	token_array[5][0]=100+tokenx;
	token_array[5][1]=111+tokeny-50;
	token_array[6][0]=118+tokenx; 
	token_array[6][1]=110+tokeny-50;
	token_array[7][0]=128+tokenx;
	token_array[7][1]=111+tokeny-50;
	token_array[8][0]=128+tokenx; 
	token_array[8][1]=111+tokeny-50;
	token_array[9][0]=121+tokenx;
	token_array[9][1]=118+tokeny-50;
	token_array[10][0]=121+tokenx;  
	token_array[10][1]=118+tokeny-50;
	token_array[11][0]=124+tokenx;
	token_array[11][1]=128+tokeny-50;
	token_array[12][0]=124+tokenx;  
	token_array[12][1]=128+tokeny-50;
	token_array[13][0]=113+tokenx;
	token_array[13][1]=123+tokeny-50;
	token_array[14][0]=113+tokenx; 
	token_array[14][1]=123+tokeny-50;
	token_array[15][0]=104+tokenx;
	token_array[15][1]=128+tokeny-50;
	token_array[16][0]=104+tokenx;
	token_array[16][1]=128+tokeny-50;
	token_array[17][0]=107+tokenx;
	token_array[17][1]=118+tokeny-50;
	token_array[18][0]=107+tokenx;
	token_array[18][1]=118+tokeny-50;
	token_array[19][0]=100+tokenx;
	token_array[19][1]=111+tokeny-50;

}






int check_hit_token(){

      int m;
      int they_intersect;
      for (m=0;m<=19;m=m+2){
        they_intersect=lineSegmentIntersection(token_array[m][0],token_array[m][1],token_array[m+1][0],token_array[m+1][1], 
                                             ship_array[1][0],ship_array[1][1],ship_array[2][0],ship_array[2][1]);
        if (they_intersect==1){
          drawstar=0;
          fuel_level=fuel_level+fuel_level_inc;
          return 0;
        }
        they_intersect=lineSegmentIntersection(token_array[m][0],token_array[m][1],token_array[m+1][0],token_array[m+1][1], 
                                               ship_array[2][0],ship_array[2][1],ship_array[3][0],ship_array[3][1]);
        if (they_intersect==1){
          drawstar=0;
          fuel_level=fuel_level+fuel_level_inc;
          return 0;
        }
        they_intersect=lineSegmentIntersection(token_array[m][0],token_array[m][1],token_array[m+1][0],token_array[m+1][1], 
    																					ship_array[3][0],ship_array[3][1],ship_array[0][0],ship_array[0][1]);
        if (they_intersect==1){
          drawstar=0;
        	fuel_level=fuel_level+fuel_level_inc;
        	return 0;
        }
        they_intersect=lineSegmentIntersection(token_array[m][0],token_array[m][1],token_array[m+1][0],token_array[m+1][1],  
                                             ship_array[0][0],ship_array[0][1],ship_array[4][0],ship_array[4][1]);
    
        if (they_intersect==1){
         drawstar=0;
         fuel_level=fuel_level+fuel_level_inc;
         return 0;
        }
        they_intersect=lineSegmentIntersection(token_array[m][0],token_array[m][1],token_array[m+1][0],token_array[m+1][1],  
                                             ship_array[4][0],ship_array[4][1],ship_array[1][0],ship_array[1][1]);
  
        if (they_intersect==1){
          drawstar=0;
          fuel_level=fuel_level+fuel_level_inc;
          return 0;
       	}


}return 0;}



void fuel_bar(){
		fprintf(sketch, "setColor 0 139 0\n");
		fprintf(sketch, "drawSegment 10 10 %d 10\n", fuel_level);
		fprintf(sketch, "drawSegment 10 11 %d 11\n", fuel_level);
		fprintf(sketch, "drawSegment 10 12 %d 12\n", fuel_level);
		fprintf(sketch, "drawSegment 10 13 %d 13\n", fuel_level);
		fprintf(sketch, "setColor 0 0 0\n");
		fflush(sketch);


}